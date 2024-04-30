#pragma once

#include "./zip/unzip.h"

#define SAFE_DELETE(p)			{ if(p) { delete (p);		(p)=NULL; }		}
#define SAFE_RELEASE(p)			{ if(p) { (p)->Release();	(p)=NULL; }		}
#define SAFE_DELETE_ARRAY(p)	{ if(p) { delete[] (p);		(p)=NULL; }		}
#define SAFE_CLOSE_HANDLE(p)	{ if(p) { CloseHandle(p);	(p) = NULL; }	}

#define LOCK(m)					std::lock_guard<std::mutex> lock(m)

// vector_3d -> VECTOR3D 로 변환. 파라메터 전달용.
#define CONVERT_VECTOR3D(v)		VECTOR3D(v.x, v.y, v.z)


#pragma region character mecro

// CUser 포인터를 선언하고 얻는다. null 체크 실패시 입력한 포멧의 로그를 남기고 리턴.
// DECLEAR_NAME : 선언할 이름.
// I64KEY : UserUID (패킷의 Key)
// FORMAT_STR : 실패시 로그 포멧.
// ... : 로그 파라메터들.
#define GET_USER_FORM_I64KEY(DECLEAR_NAME, I64KEY, FORMAT_STR, ...)\
CUser* DECLEAR_NAME = userManager.Get(I64KEY);\
if (nullptr == DECLEAR_NAME)\
{\
	SERVER_LOG(eServerLogType::eWarning, FORMAT_STR, __VA_ARGS__);\
	return;\
}

// CCharacter 포인터를 선언하고 얻는다. null 체크 실패시 입력한 포멧의 로그를 남기고 리턴.
// DECLEAR_NAME : 선언할 이름.
// USER_PTR : 획득한 User포인터. 따로 null체크 안함.
// FORMAT_STR : 실패시 로그 포멧.
// ... : 로그 파라메터들.
#define GET_CHARACTER_FROM_USER_LOG(DECLEAR_NAME, USER_PTR, FORMAT_STR, ...)\
CCharacter* DECLEAR_NAME = USER_PTR->GetCharacter();\
if (nullptr == DECLEAR_NAME)\
{\
	SERVER_LOG(eServerLogType::eWarning, FORMAT_STR, __VA_ARGS__);\
	return;\
}

// CCharacter 포인터를 선언하고 얻는다. null 체크 실패시 대상 에러 응답 처리 수행 후 리턴.
// DECLEAR_NAME : 선언할 이름.
// USER_PTR : 획득한 User포인터. 따로 null체크 안함.
// CMD_TYPE : 응답할 패킷 타입.
// ERROR_CODE : 응답에 보낼 오류 메세지.
#define GET_CHARACTER_FROM_USER_RESPONSE(DECLEAR_NAME, USER_PTR, CMD_TYPE, ERROR_CODE)\
CCharacter* DECLEAR_NAME = USER_PTR->GetCharacter();\
if (nullptr == DECLEAR_NAME)\
{\
	networkManager.SendErrorMessage(CMD_TYPE, USER_PTR->GetSession(), ERROR_CODE);\
	return;\
}

// CCharacter 포인터를 선언하고 얻는다. null 체크 실패시 입력한 포멧의 로그, 에러 응답 처리 수행 후 리턴.
// DECLEAR_NAME : 선언할 이름.
// USER_PTR : 획득한 User포인터. 따로 null체크 안함.
// CMD_TYPE : 응답할 패킷 타입.
// ERROR_CODE : 응답에 보낼 오류 메세지.
// FORMAT_STR : 실패시 로그 포멧.
// ... : 로그 파라메터들.
#define GET_CHARACTER_FROM_USER_LOG_RESPONSE(DECLEAR_NAME, USER_PTR, CMD_TYPE, ERROR_CODE, FORMAT_STR, ...)\
CCharacter* DECLEAR_NAME = USER_PTR->GetCharacter();\
if (nullptr == DECLEAR_NAME)\
{\
	SERVER_LOG(eServerLogType::eWarning, FORMAT_STR, __VA_ARGS__);\
	networkManager.SendErrorMessage(CMD_TYPE, USER_PTR->GetSession(), ERROR_CODE);\
	return;\
}

#pragma endregion character mecro


#pragma region rpc mecro

// rpc 포인터를 선언 하고 얻는다. null 체크 실패시 로그 처리 하고 리턴.
// DELCEAR_NAME : 선언할 이름.
// SERVER_TYPE : mrpce_server_type
// GID : 서버gid
// FORMAT_STR : rpc 탐색 실패시 로그 포멧
// ... : 로그 파라메터들.
#define GET_RPC_WORLD_LOG(DELCEAR_NAME, SERVER_TYPE, GID, FORMAT_STR, ...)\
CRpc* DELCEAR_NAME = rpcManager.GetRpcWorld(SERVER_TYPE, GID);\
if (nullptr == DELCEAR_NAME || false == DELCEAR_NAME->GetSession())\
{\
	SERVER_LOG(eServerLogType::eWarning, FORMAT_STR, __VA_ARGS__);\
	return;\
}

// rpc 포인터를 선언 하고 얻는다. null 체크 실패시 에러 응답 처리 하고 리턴.
// DELCEAR_NAME : 선언할 이름.
// SERVER_TYPE : mrpce_server_type
// GID : 서버gid
// CMD_TYPE : 응답할 패킷 메세지.
// SESSION : 세션 포인터.
// ERROR_CODE : 보낼 에러 코드.
#define GET_RPC_WORLD_RESPONSE(DELCEAR_NAME, SERVER_TYPE, GID, CMD_TYPE, SESSION, ERROR_CODE)\
CRpc* DELCEAR_NAME = rpcManager.GetRpcWorld(SERVER_TYPE, GID);\
if (nullptr == DELCEAR_NAME || false == DELCEAR_NAME->GetSession())\
{\
	networkManager.SendErrorMessage(CMD_TYPE, SESSION, ERROR_CODE);\
	return;\
}

// rpc 포인터를 선언 하고 얻는다. null 체크 실패시 로그, 에러 응답 처리 하고 리턴.
// DELCEAR_NAME : 선언할 이름.
// SERVER_TYPE : mrpce_server_type
// GID : 서버gid
// CMD_TYPE : 응답할 패밋 메세지.
// SESSION : 세션 포인터.
// ERROR_CODE : 보낼 에러 코드.
// FORMAT_STR : rpc 탐색 실패시 로그 포멧
// ... : 로그 파라메터들.
#define GET_RPC_WORLD_LOG_RESPONSE(DELCEAR_NAME, SERVER_TYPE, GID, CMD_TYPE, SESSION, ERROR_CODE, FORMAT_STR, ...)\
CRpc* DELCEAR_NAME = rpcManager.GetRpcWorld(SERVER_TYPE, GID);\
if (nullptr == DELCEAR_NAME || false == DELCEAR_NAME->GetSession())\
{\
	SERVER_LOG(eServerLogType::eWarning, FORMAT_STR, __VA_ARGS__);\
	networkManager.SendErrorMessage(CMD_TYPE, SESSION, ERROR_CODE);\
	return;\
}

#pragma endregion rpc mecro


#pragma region party mecro

// CParty 포인터를 선언하고 파티를 생성한다. null 체크 실패시 입력한 로그를 남기고 리턴.
// DECLEAR_NAME : 선언할 파티 포인터 이름.
// PARTY_BASE_INFO : 패킷으로 부터 받은 파티 기본 정보.
// FORMAT_STR : 실패시 남길 로그 포멧.
// ... : 로그 파라메터들.
#define CREATE_PARTY_FROM_BASE_LOG(DECLEAR_NAME, PARTY_BASE_INFO, FORMAT_STR, ...)\
CParty* DECLEAR_NAME = partyManager.PartyCreate(PARTY_BASE_INFO);\
if (nullptr == DECLEAR_NAME)\
{\
	SERVER_LOG(eServerLogType::eWarning, FORMAT_STR, __VA_ARGS__);\
	return;\
}

// CParty 포인터를 선언하고 파티 정보를 얻는다. null 체크 실패시 입력한 로그를 남기고 리턴.
// DECLEAR_NAME : 선언할 파티 이름.
// PUID : 파티 uid.
// FORMAT_STR : 실패시 로그 포멧.
// ... : 로그 파라메터들.
#define GET_PARTY_LOG(DECLEAR_NAME, PUID, FORMAT_STR, ...)\
CParty* DECLEAR_NAME = partyManager.Get(PUID);\
if (nullptr == DECLEAR_NAME)\
{\
	SERVER_LOG(eServerLogType::eWarning, FORMAT_STR, PUID);\
	return;\
}

#pragma endregion party mecro


namespace mir3d
{
	extern void Decompression(std::string target_file, std::string target_dir);
}   //namespace mir3d	
