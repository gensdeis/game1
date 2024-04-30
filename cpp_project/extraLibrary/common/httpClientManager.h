#pragma once

#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/lock_guard.hpp>

#if defined(_MULTI_CLIENT) || defined(_MULTI_STRESS)
#include "http_process.h"
#include "http_network.h"

namespace mir3d
{
	

	typedef boost::function< void(CDummy *, std::vector<unsigned char> ) > fp_callback_t;

	enum HTTP_ERROR_CODE
	{
		SUCCESS,
		EMPTY_REPLY,
		TIME_OUT,
		HTTP_ERROR,
		EXCEPTION,

	};

	struct CResponse
	{
	private:
		std::vector<unsigned char>	m_vtContent;
		fp_callback_t				m_fp_callback;
		CDummy			*			m_dummy;

	public:
		CResponse(CDummy * _dummy, std::vector<unsigned char> & vtContent, fp_callback_t _fp_callback)
			: m_vtContent(vtContent)
			, m_dummy(_dummy)
			, m_fp_callback(_fp_callback)
		{}


		void operator()() const
		{

			if (m_fp_callback)
				m_fp_callback(m_dummy, m_vtContent);

		}

	};

	struct http_request : public tasks_processor
	{
		void request_by_json(sp_http_client _client)
		{
			// 리셋 한다.
			reset();

			_client->push_task();

			// 실행
			run_through_thread();

			//_client->run( m_ios );
		}
	};

	struct http_response : public tasks_processor
	{
		void response_content(const CResponse& _res)
		{
			_res();
			//push_task(_res);
		}
	};

	class httpClientManager :public CSingleton<httpClientManager>
	{
	public:

		httpClientManager();
		virtual ~httpClientManager();
	public:
		void poll_response()
		{
			m_response.poll();
		}

		void response_content(CDummy * _dummy, std::vector<unsigned char> & content_, fp_callback_t _f)
		{
			CResponse(_dummy, content_, _f)();
			//m_response.response_content(CResponse(_dummy, content_, _f));
		}

		// 아직은 아무것도 안함
		void response_body(const std::string& content_)
		{
		}

		/*void remove_stopped_request()
		{
			for (std::list<boost::shared_ptr<http_request>>::iterator it = m_requests.begin(), end = m_requests.end(); it != end; ++it)
			{
				if ((*it)->stopped())
					it = m_requests.erase(it);
			}
		}*/

		void SendWebPost(CDummy * dummy, const std::string& url, const std::string& port, const std::string& path_, const std::string& req_data_, fp_callback_t _f)
		{

			//boost::lock_guard<boost::mutex> guard(m_mutex);
			// 정지된 요청 삭제
			//remove_stopped_request();

			boost::shared_ptr<http_request> new_request = boost::make_shared< http_request >();//(new http_request());
			//m_requests.push_back(new_request);
			new_request->request_by_json(boost::make_shared< http_client >(boost::ref(new_request->get_ios()), dummy, url, port, path_, req_data_, _f));

		}
		void SendWebGet(CDummy * dummy, const std::string& url, const std::string& port, const std::string& path_, fp_callback_t _f)
		{
			//boost::lock_guard<boost::mutex> guard(m_mutex);
			// 정지된 요청 삭제
			//remove_stopped_request();
			boost::shared_ptr<http_request> new_request = boost::make_shared< http_request >();
			//http_request* new_request(new http_request());
			//m_requests.push_back(new_request);
			new_request->request_by_json(boost::make_shared< http_client >(boost::ref(new_request->get_ios()), dummy, url, port, path_, _f));
		}
		// json 으로 요청함
		//void request_by_json(CDummy * dummy, const std::string& server_, const std::string& path_, const std::string& json_data_, fp_callback_t _f)
		//{
		//	//boost::lock_guard<boost::mutex> guard(m_mutex);

		//	// 정지된 요청 삭제
		//	//remove_stopped_request();

		//	//http_request* new_request(new http_request());
		//	//m_requests.push_back(new_request);

		//	//new_request->request_by_json(boost::make_shared< http_client >(boost::ref(new_request->get_ios()), dummy, server_, path_, json_data_, _f));

		//}
	private:
		//boost::mutex m_mutex;
		// http request
		//std::list< boost::shared_ptr<http_request> > m_requests;
		const char* GetAddrIP(const char* domain);
		// http response
		http_response m_response;

	public:
		template<typename T_WebPacket>
		void SendWebPostRequest(CDummy * dummy, const std::string& url, const std::string& port, const std::string& page, const T_WebPacket* contents, fp_callback_t _f)
		{
			if (contents == nullptr)
				return;

			mir3d::protocol::SerializeBufferNative buffer;
			mir3d::protocol::SerializeType(&buffer, contents);

			std::string reqString = "";
			reqString.append(reinterpret_cast<const char *>(buffer.GetBufferPointer()), buffer.GetBufferLength());

			SendWebPost(dummy, url, port, page, reqString, _f);
			

		}
		void SendWebGetRequest(CDummy * dummy, const std::string& url, const std::string& port, const std::string& page, fp_callback_t _f)
		{
			SendWebGet(dummy, url, port, page, _f);
			
		}
		///********************************************************************************
		// 
		// ********************************************************************************/

		void GetLoginAuthServerInfo(CDummy * client);
		void OnLoginAuthServerInfo(CDummy * client, const std::vector<unsigned char> ResponseData);

		void GetLoginAuth(CDummy * client);
		void OnLoginAuth(CDummy * client, const std::vector<unsigned char> ResponseData);

		void CSLogin_LobbyLogin(CDummy * client);
		void SCLogin_LobbyLogin(CDummy * client, const std::vector<unsigned char> ResponseData);

		void CSLogin_GameLogin(CDummy * client);
		void SCLogin_GameLogin(CDummy * client, const std::vector<unsigned char> ResponseData);

		void CSSelectCharacter(CDummy * client);
		void SCSelectCharacter(CDummy * client, const std::vector<unsigned char> ResponseData);

		void CSCreateCharacter(CDummy * client);
		void SCCreateCharacter(CDummy * client, const std::vector<unsigned char> ResponseData);

	private:

	};

#define httpManager httpClientManager::getInstance()
}
#endif
