#pragma once
#include <common/mirapi.h>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/thread/thread.hpp>

using boost::asio::ip::tcp;
#if defined(_MULTI_CLIENT) || defined(_MULTI_STRESS)

namespace mir3d
{	


	class CDummy;

	class http_client : public boost::enable_shared_from_this<http_client>
	{
		typedef boost::function< void(CDummy *, std::vector<unsigned char>) > fp_result_t;
	public:

		explicit http_client(boost::asio::io_service& io_service_, CDummy * dummy, const std::string& ip_, const std::string& port_, const std::string& path_, fp_result_t fp_result_);
		explicit http_client(boost::asio::io_service& io_service_, CDummy * dummy, const std::string& ip_, const std::string& port_, const std::string& path_, const std::string& post_data_, fp_result_t fp_result_);

		~http_client();

		inline void push_task() { resolve(); }

	private:

		tcp::resolver m_resolver;
		tcp::socket m_socket;
		boost::asio::streambuf m_request;
		boost::asio::streambuf m_response;

		// 매개변수들..
		std::string m_server; // 주소
		std::string m_ip; // 아이피
		std::string m_port; // 포트
		std::string m_path; // 경로
		std::string m_post_data; // post 로 보낼시 데이터
		CDummy * m_dummy;
		// 콜백 받을 함수 타입
		
		//std::string m_content; // 내용
		std::vector<unsigned char> m_vtResponseData;
		fp_result_t m_fp_result;
	protected:

		//
		// domain 을 가지고 ip 주소를 찾는다.
		//
		void resolve();
		//
		// resolve 결과 
		//
		void handle_resolve(boost::shared_ptr< http_client > client, const boost::system::error_code& err, tcp::resolver::iterator endpoint_iterator);
		//
		// 소켓 연결 결과
		//
		void handle_connect(boost::shared_ptr< http_client > client, const boost::system::error_code& err);
		//
		// http 요청 결과
		//
		void handle_write_request(boost::shared_ptr< http_client > client, const boost::system::error_code& err);
		//
		// 응답 결과
		//
		void handle_read_status_line(boost::shared_ptr< http_client > client, const boost::system::error_code& err);
		//
		// http 헤더를 읽어온다.
		//
		void handle_read_headers(boost::shared_ptr< http_client > client, const boost::system::error_code& err);
		//
		// http 컨텐츠를 읽어온다.
		//
		void handle_read_content(boost::shared_ptr< http_client > client, const boost::system::error_code& err);
	public:

	};
	// shared pointer
	typedef boost::shared_ptr< http_client > sp_http_client;

} // namespace mir3d
#endif