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

		// �Ű�������..
		std::string m_server; // �ּ�
		std::string m_ip; // ������
		std::string m_port; // ��Ʈ
		std::string m_path; // ���
		std::string m_post_data; // post �� ������ ������
		CDummy * m_dummy;
		// �ݹ� ���� �Լ� Ÿ��
		
		//std::string m_content; // ����
		std::vector<unsigned char> m_vtResponseData;
		fp_result_t m_fp_result;
	protected:

		//
		// domain �� ������ ip �ּҸ� ã�´�.
		//
		void resolve();
		//
		// resolve ��� 
		//
		void handle_resolve(boost::shared_ptr< http_client > client, const boost::system::error_code& err, tcp::resolver::iterator endpoint_iterator);
		//
		// ���� ���� ���
		//
		void handle_connect(boost::shared_ptr< http_client > client, const boost::system::error_code& err);
		//
		// http ��û ���
		//
		void handle_write_request(boost::shared_ptr< http_client > client, const boost::system::error_code& err);
		//
		// ���� ���
		//
		void handle_read_status_line(boost::shared_ptr< http_client > client, const boost::system::error_code& err);
		//
		// http ����� �о�´�.
		//
		void handle_read_headers(boost::shared_ptr< http_client > client, const boost::system::error_code& err);
		//
		// http �������� �о�´�.
		//
		void handle_read_content(boost::shared_ptr< http_client > client, const boost::system::error_code& err);
	public:

	};
	// shared pointer
	typedef boost::shared_ptr< http_client > sp_http_client;

} // namespace mir3d
#endif