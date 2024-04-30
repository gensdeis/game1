#include "stdafx.h"
#include "rpc.h"
#include <protocol/rpc_protocol_enumstring.h>

namespace mir3d
{
	CRpc::CRpc()
	{
#ifdef _NOT_USE
		_use_count.exchange(0);
#endif
		_heartbeat_uid = mir3d::util::uidGenerate.Get(util::CUidGenerate::eUid::trade);
	}

	CRpc::CRpc(const mrpcs_redis_rpcinfo& info) : _type(info.type), _index(info.index), _ip(info.ip), _port(info.port), _gid(info.gid)
	{
		_step = eStep::ready;

		std::stringstream server_name;
		server_name << std::to_string(info.gid) << "_" << _type << "_" << std::to_string(_index);

		_full_tag.assign(server_name.str());
#ifdef _NOT_USE	
		_use_count.exchange(0);
#endif
		_heartbeat_uid = mir3d::util::uidGenerate.Get(util::CUidGenerate::eUid::trade);
	}

	CRpc::~CRpc()
	{
		_session = nullptr;
	}

	const std::string& CRpc::GetRemoteInfo(void)
	{
		if (nullptr != _session)
		{
			return _session->GetRemoteInfo();
		}

		return _temp_string;
	}

	void CRpc::ForceDisconnect(const char* call_func)
	{
		if (nullptr != _session)
		{
			_session->ForceDisconnect(call_func);
		}
	}

	void CRpc::Send(std::shared_ptr<CSocketWriteBuffer>& data)
	{
		if (nullptr != _session)
		{
			_session->Send(data);
		}
	}
}	// namespace mir3d

