#include "stdafx_net.h"
#include "httpClientManager.h"
#include <iostream>

#include <protocol/mweb_login_loginauth.h>
#include <protocol/mweb_login_lobbylogin.h>
#include <protocol/mweb_lobby_gamelogin.h>
#include <protocol/mweb_lobby_character_select.h>
#include <protocol/mweb_lobby_character_create.h>


#if defined(_MULTI_CLIENT) || defined(_MULTI_STRESS)
#ifdef _MULTI_CLIENT
#include "../../AIService/dummy.h"
#include "../../AIService/dummyThreadManager.h"

#elif defined(_MULTI_STRESS)
#include "../../multiStressTest/dummy.h"
#include "../../multiStressTest/dummyThreadManager.h"
#endif

//#include <common/util.h>

using namespace std;
namespace mir3d
{
	
	httpClientManager::httpClientManager()
	{

	}
	httpClientManager::~httpClientManager()
	{
		
	}
	
	void httpClientManager::GetLoginAuthServerInfo(CDummy * client)
	{    
		std::string url;
		std::string page;
		std::string port;
		dummyConfigManager.GetServerAddress(dummyConfigManager.front_server, url, port, page);

		
		SendWebGetRequest(client, url, port, page, boost::bind(&httpClientManager::OnLoginAuthServerInfo, this, _1, _2));
	    
	    
	}
	void httpClientManager::OnLoginAuthServerInfo(CDummy * client, const std::vector<unsigned char> ResponseData)
	{

		std::string strResponse(ResponseData.begin(), ResponseData.end());
		Json::Reader reader;
		Json::Value root;
		bool parsingRet = reader.parse(strResponse, root);

		if (!parsingRet)
		{
			std::cout << "Failed to parse Json : " << reader.getFormattedErrorMessages();
			return;
		}


		Json::Value serverinfos = root;
		for (auto it = serverinfos.begin(); it != serverinfos.end(); it++)
		{
			string s = (*it)["version"].asString();

			
			if (0 == dummyConfigManager.version.compare(s))
			{
				client->_login_url = (*it)["login_server"].asString();
				break;
			}
		}

		client->_state = eState::LoginAuth;
		GetLoginAuth(client);

	}

	void httpClientManager::GetLoginAuth(CDummy * client)
	{

		std::string url;
		std::string page = "/login/loginauth";
		std::string port;
		dummyConfigManager.GetServerAddress(client->_login_url, url, port, page);

		mweb_login_loginauth_cs req;
		req.username = client->_user_name;

		SendWebPostRequest<mweb_login_loginauth_cs>(client, url,port, page, &req, boost::bind(&httpClientManager::OnLoginAuth, this, _1, _2));


	}
	void httpClientManager::OnLoginAuth(CDummy * client, const std::vector<unsigned char> ResponseData)
	{
		int len = (int)ResponseData.size();
		
		mweb_login_loginauth_sc tempPacket;
		LOG(INFO) << "OnLoginAuth len : " << len ;

		mir3d::protocol::UnSerializeNative(ResponseData.data(), (int)ResponseData.size(), &tempPacket);
		if (tempPacket.result != 0)
		{
		     return;
		}
		//auid
		if (tempPacket.has_info())
		{

			const mps_login_account* account = tempPacket.get_info();

			if (account && account->auid > 0)
			{
				client->_auid = account->auid;
			}
			else
			{
				//"SCLoginAuthFail";
				return;
			}

			//auto list_server = tempPacket.list_server;
			//for (size_t i = 0; i < tempPacket.list_server.size(); i++)
			//{
			//	if (dummyConfigManager.version.compare("dev") == 0)
			//	{
			//		client->_gid = 40001;//서버 전용
			//		break;
			//
			//	}
			//	else if(dummyConfigManager.version.compare("default") == 0)
			//	{
			//		client->_gid = tempPacket.list_server[i].gid;
			//		break;
			//	}
			//	else if (dummyConfigManager.my_server.compare(tempPacket.list_server[i].name) == 0)
			//	{
			//		client->_gid = tempPacket.list_server[i].gid;
			//		break;
			//	}
			//}
			
			client->_gid = dummyConfigManager.gid;

			client->_state = eState::LobbyLogin;
			CSLogin_LobbyLogin(client);
		}
	}

	void httpClientManager::CSLogin_LobbyLogin(CDummy * client)
	{

		std::string url;
		std::string page = "/login/lobbylogin";
		std::string port;
		dummyConfigManager.GetServerAddress(client->_login_url, url, port, page);

		mweb_login_lobbylogin_cs req;
		req.username = client->_user_name;
		req.quicklogin = false;
		req.gid = client->_gid;


		SendWebPostRequest<mweb_login_lobbylogin_cs>(client, url, port, page, &req, boost::bind(&httpClientManager::SCLogin_LobbyLogin, this, _1, _2));


	}
	void httpClientManager::SCLogin_LobbyLogin(CDummy * client, const std::vector<unsigned char> ResponseData)
	{
		int len = (int)ResponseData.size();
		std::vector<unsigned char> buffer(len);

		
		LOG(INFO) << "SCLogin_LobbyLogin len :" << len ;

		mweb_login_lobbylogin_sc responsePacket;
		mir3d::protocol::UnSerializeNative(ResponseData.data(), (int)ResponseData.size(), &responsePacket);
		
		if ((int)0 == responsePacket.result)
		{
			if (0 == responsePacket.list_lobby.size())
			{
				return ;
			}

			client->_access_token = responsePacket.access_token;

			for (int i = 0, len = (int)responsePacket.list_lobby.size(); i < len; i++)
			{
				//_list_lobby.Add((responsePacket.list_lobby[i].url).Trim('\0'));
				client->_lobby_url = responsePacket.list_lobby[i].url;
				break;
			}
		}
		else
		{
		/*	var table = TableManager.instance.ServerMessageTable.Get(responsePacket.result);
			if (null != table) mir3d.logger.Info(table.text);*/

			return ;
		}
		client->_state = eState::GameLogin;
		CSLogin_GameLogin(client);
	}
	
	void httpClientManager::CSLogin_GameLogin(CDummy * client)
	{

		std::string url;
		std::string page = "/lobby/gamelogin";
		std::string port;
		dummyConfigManager.GetServerAddress(client->_lobby_url, url, port, page);

		mweb_lobby_gamelogin_cs req;
		req.auid = client->_auid;
		req.access_token = client->_access_token;


		SendWebPostRequest<mweb_lobby_gamelogin_cs>(client, url, port, page, &req, boost::bind(&httpClientManager::SCLogin_GameLogin, this, _1, _2));


	}
	void httpClientManager::SCLogin_GameLogin(CDummy * client, const std::vector<unsigned char> ResponseData)
	{
		int len = (int)ResponseData.size();
		

		mweb_lobby_gamelogin_sc responsePacket;
		mir3d::protocol::UnSerializeNative(ResponseData.data(), (int)ResponseData.size(), &responsePacket);

		if ((int)0 == responsePacket.result)
		{
			if (responsePacket.has_gameinfo())
			{
				const mps_lobby_gameinfo* gameinfo = responsePacket.get_gameinfo();
				//BoardServerUrl_ = gameinfo->board_url;
				client->_game_ip = gameinfo->server_ip;
				client->_game_port = gameinfo->server_port;
				client->_quick_login = gameinfo->quicklogin;

				client->SetLoginType(E_Login_Type::Quick);
				client->_state = eState::ConnectServer;
				dummyManager.ConnectGameServer(client);
				client->_isZoneType = mrpce_server_type::game;
				return;
			}

			//Normal Login
			if (responsePacket.has_player())
			{
				const mps_lobby_player* lobby_player = responsePacket.get_player();

				client->_last_cuid = (lobby_player->last_cuid);

				if (lobby_player->list_character.size() > 0)
				{
					for (int i = 0; i < lobby_player->list_character.size(); i++)
					{

						const mps_lobby_character& lobby_character = lobby_player->list_character[i];
						client->Add_Lobby_Character(lobby_character);
						
					}
					client->SetAccountLogin(true);

					client->SetLoginType(E_Login_Type::Normal);

					client->_state = eState::CharacterSelect;
					CSSelectCharacter(client);
				}
				else
				{
					client->_state = eState::CharacterCreate;
					CSCreateCharacter(client);
				}
				

			}
			else
			{
				client->_state = eState::CharacterCreate;
				CSCreateCharacter(client);
			}

		}
	}

	void httpClientManager::CSSelectCharacter(CDummy * client)
	{

		std::string url;
		std::string page = "/lobby/characterselect";
		std::string port;
		dummyConfigManager.GetServerAddress(client->_lobby_url, url, port, page);

		mweb_lobby_character_select_cs request;
		request.auid = client->_auid;
		request.cuid = client->LobbyCharacterList.front().CUID;
		request.access_token = client->_access_token;


		SendWebPostRequest<mweb_lobby_character_select_cs>(client, url, port, page, &request, boost::bind(&httpClientManager::SCSelectCharacter, this, _1, _2));


	}
	const char * httpClientManager::GetAddrIP(const char* domain)
	{
		//----------------------------------------- // Declare and initialize variables
		string strip = "";
		
		INT iRetval;
		DWORD dwRetval;
		int i = 1;
		struct addrinfo* result = NULL;
		struct addrinfo* ptr = NULL;
		struct addrinfo hints;
		struct sockaddr_in* sockaddr_ipv4;
		// struct sockaddr_in6 *sockaddr_ipv6;
		LPSOCKADDR sockaddr_ip;
		char ipstringbuffer[46];
		DWORD ipbufferlength = 46;
		// Validate the parameters
	
		//-------------------------------- 
		// Setup the hints address info structure 
		// which is passed to the getaddrinfo() function 
		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		printf("Calling getaddrinfo with following parameters:\n");
		printf("\tnodename = %s\n", domain);
		//printf("\tservname (or port) = %s\n\n", argv[2]);
		//-------------------------------- 
		// Call getaddrinfo(). If the call succeeds, 
		// the result variable will hold a linked list 
		// of addrinfo structures containing response 
		// information 
		dwRetval = getaddrinfo(domain, nullptr, &hints, &result);
		if (dwRetval != 0)
		{
			printf("getaddrinfo failed with error: %d\n", dwRetval);
			return "";
		}
		printf("getaddrinfo returned success\n");
		// Retrieve each address and print out the hex bytes 
		for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
		{
			printf("getaddrinfo response %d\n", i++);
			printf("\tFlags: 0x%x\n", ptr->ai_flags);
			printf("\tFamily: ");
			switch (ptr->ai_family)
			{
			case AF_UNSPEC:
				printf("Unspecified\n");
				break;
			case AF_INET:
				printf("AF_INET (IPv4)\n");
				sockaddr_ipv4 = (struct sockaddr_in*) ptr->ai_addr;
				//inet_ntop();
				//InetNtop()
				strip = inet_ntoa(sockaddr_ipv4->sin_addr);
				printf("\tIPv4 address %s\n", inet_ntoa(sockaddr_ipv4->sin_addr));
				break;
			case AF_INET6:
				printf("AF_INET6 (IPv6)\n");
				// the InetNtop function is available on Windows Vista and later 
				// sockaddr_ipv6 = (struct sockaddr_in6 *) ptr->ai_addr; 
				// printf("\tIPv6 address %s\n", 
				// InetNtop(AF_INET6, &sockaddr_ipv6->sin6_addr, ipstringbuffer, 46) ); 
				// We use WSAAddressToString since it is supported on Windows XP and later 
				sockaddr_ip = (LPSOCKADDR) ptr->ai_addr; 
				// The buffer length is changed by each call to WSAAddresstoString 
				// So we need to set it for each iteration through the loop for safety 
				ipbufferlength = 46;
				iRetval = WSAAddressToString(sockaddr_ip, (DWORD)ptr->ai_addrlen, NULL, ipstringbuffer, &ipbufferlength);
				if (iRetval) printf("WSAAddressToString failed with %u\n", WSAGetLastError());
				else printf("\tIPv6 address %s\n", ipstringbuffer);
				break;
			case AF_NETBIOS:
				printf("AF_NETBIOS (NetBIOS)\n");
				break;

			default:
				printf("Other %ld\n", ptr->ai_family);
				break;
			}
			printf("\tSocket type: ");
			switch (ptr->ai_socktype)
			{
			case 0: printf("Unspecified\n"); break;
			case SOCK_STREAM: printf("SOCK_STREAM (stream)\n"); break;
			case SOCK_DGRAM: printf("SOCK_DGRAM (datagram) \n"); break;
			case SOCK_RAW: printf("SOCK_RAW (raw) \n"); break;
			case SOCK_RDM: printf("SOCK_RDM (reliable message datagram)\n"); break;
			case SOCK_SEQPACKET: printf("SOCK_SEQPACKET (pseudo-stream packet)\n"); break;
			default: printf("Other %ld\n", ptr->ai_socktype); break;
			} printf("\tProtocol: ");
			switch (ptr->ai_protocol)
			{
			case 0: printf("Unspecified\n"); break;
			case IPPROTO_TCP: printf("IPPROTO_TCP (TCP)\n"); break;
			case IPPROTO_UDP: printf("IPPROTO_UDP (UDP) \n"); break;
			default: printf("Other %ld\n", ptr->ai_protocol); break;
			}
			printf("\tLength of this sockaddr: %zd\n", ptr->ai_addrlen);
			printf("\tCanonical name: %s\n", ptr->ai_canonname);
		}
		freeaddrinfo(result);
	
		return strip.c_str();
	}

	void httpClientManager::SCSelectCharacter(CDummy * client, const std::vector<unsigned char> ResponseData)
	{
		int len = ResponseData.size();
	
		mweb_lobby_character_select_sc responsePacket;
		mir3d::protocol::UnSerializeNative(ResponseData.data(), ResponseData.size(), &responsePacket);

		if ((int)0 == responsePacket.result)
		{
			client->_access_token = responsePacket.access_token;
			if (responsePacket.has_gameinfo())
			{
				string server_ip = responsePacket.get_gameinfo()->server_ip;
				//struct hostent *pHost;
				//struct in_addr *pAddr; 
				string strip;
				int ret = 0;
				// 알파벳으로 시작하는 이름일 경우에는 domain name으로 간주합니다.
				if (((server_ip[0] > 'A') && (server_ip[0] < 'Z')) || ((server_ip[0] > 'a') && (server_ip[0] < 'z'))) {
					
					strip = GetAddrIP(server_ip.c_str());
					if (strip == "")
					{
#ifdef WIN32
						ret = WSAGetLastError();
#endif
						LOG(ERROR) << "Error in GetAddrIP(), error code = " << ret;
					}
					/*pHost = gethostbyname(server_ip.c_str());
					if (pHost == NULL) {
#ifdef WIN32
						ret = WSAGetLastError();
#endif
						printf("Error in gethostbyname(), error code = %d\n", ret);

					}
					else {
						printf("Official name of the host is: '%s'\n", pHost->h_name);
						while (*pHost->h_addr_list != NULL) {
							pAddr = reinterpret_cast<in_addr *>(*(pHost->h_addr_list));
							printf("%s\n", inet_ntoa(*pAddr));
							strip = inet_ntoa(*pAddr);
							pHost->h_addr_list++;
							
						}
					}*/
				}
				else
				{
					strip = server_ip;
				}
				
				//inet_ntop(AF_INET, &(pAddr->S_un), strip, INET_ADDRSTRLEN);
				client->_game_ip = strip;
				client->_game_port = responsePacket.get_gameinfo()->server_port;
			
				client->_state = eState::ConnectServer;
				dummyManager.ConnectGameServer(client);
				client->_isZoneType = mrpce_server_type::game;
			}
			else
			{
				return;
			}

		}
	}

	void httpClientManager::CSCreateCharacter(CDummy * client)
	{

		std::string url;
		std::string page = "/lobby/charactercreate";
		std::string port;
		dummyConfigManager.GetServerAddress(client->_lobby_url, url, port, page);

		mweb_lobby_character_create_cs request;
		request.auid = client->_auid;
		
		request.nickname = client->_user_name;
		request.access_token = client->_access_token;
		
		request.id = client->_character_type;

		SendWebPostRequest<mweb_lobby_character_create_cs>(client, url, port, page, &request, boost::bind(&httpClientManager::SCCreateCharacter, this, _1, _2));


	}
	void httpClientManager::SCCreateCharacter(CDummy * client, const std::vector<unsigned char> ResponseData)
	{
		int len = (int)ResponseData.size();
		
		mweb_lobby_character_create_sc responsePacket;
		mir3d::protocol::UnSerializeNative(ResponseData.data(), ResponseData.size(), &responsePacket);


		if ((int)0 == responsePacket.result)
		{
			
			LobbyCharacter character;
			character.CUID = responsePacket.cuid;
			character.NICK_NAME = responsePacket.nickname;
			character.LEVEL = 1;
			character.ID = responsePacket.id;


			client->LobbyCharacterList.emplace_back(character);

			/*mir3d.logger.Info("=================CREATE CHARACTER===================");
			mir3d.logger.Info("NICK_NAME : " + character.NICK_NAME);
			mir3d.logger.Info("LEVEL : " + character.LEVEL);
			mir3d.logger.Info("==================================================");*/
			client->_state = eState::CharacterSelect;
			CSSelectCharacter(client);
		}

	}
}

#endif