#include "stdafx_net.h"
#include "http_network.h"
#include "httpClientManager.h"
#include <boost/lexical_cast.hpp>

#if defined(_MULTI_CLIENT) || defined(_MULTI_STRESS)

#if defined(_MULTI_CLIENT)
#include "../AIService/dummy.h"
#else
#include "../multiStressTest/dummy.h"
#endif
namespace mir3d
{
	
		http_client::http_client(boost::asio::io_service& io_service_, CDummy * dummy, const std::string& ip_, const std::string& port_, const std::string& path_, fp_result_t fp_result_)
			: m_resolver(io_service_)
			, m_socket(io_service_)
			, m_dummy(dummy)
			, m_ip(ip_)
			, m_port(port_)
			, m_path(path_)
			, m_post_data("")
			, m_fp_result(fp_result_)
		{
			//m_content = "";
			m_vtResponseData.clear();
		}

		http_client::http_client(boost::asio::io_service& io_service_,CDummy * dummy, const std::string& ip_, const std::string& port_, const std::string& path_, const std::string& post_data_, fp_result_t fp_result_)
			: m_resolver(io_service_)
			, m_socket(io_service_)
			, m_dummy(dummy)
			, m_ip(ip_)
			, m_port(port_)
			, m_path(path_)
			, m_post_data(post_data_)
			, m_fp_result(fp_result_)
		{
			//m_content = "";
			m_vtResponseData.clear();
		}


		http_client::~http_client()
		{
			//m_thread_gp.join_all();
		}

		void http_client::resolve()
		{
			// Start an asynchronous resolve to translate the server and service names
			// into a list of endpoints.
			// 비동기 resolve 시작
			// 실제 주소를 알아오는 과정
			tcp::resolver::query query(m_ip, m_port);
			m_resolver.async_resolve(query,
				boost::bind(&http_client::handle_resolve,
					this,
					this->shared_from_this(),
					boost::asio::placeholders::error,
					boost::asio::placeholders::iterator)
			);
			//httpSystem.response_content(client->m_dummy, "http_client::resove()", m_fp_result);
		}


		//
		// resolve 가 완료됨
		//
		void http_client::handle_resolve(boost::shared_ptr< http_client > client, const boost::system::error_code& err, tcp::resolver::iterator endpoint_iterator)
		{
			if (!err)
			{
				// Form the request. We specify the "Connection: close" header so that the
				// server will close the socket after transmitting the response. This will
				// allow us to treat all data up until the EOF as the content.
				// out stream 을 생선한다.
				// 
				std::ostream request_stream(&m_request);

				// http header 정보를 넣는다.
				std::string method = m_post_data.length() > 0 ? "POST " : "GET ";

				if (method == "GET ")
				{
					request_stream << method << m_path << " HTTP/1.0\r\n";
					request_stream << "Host: " << m_ip << "\r\n";
					request_stream << "Accept: */*\r\n";
					request_stream << "Connection: close\r\n\r\n";
				}
				else
				{
					request_stream << method << m_path << " HTTP/1.0\r\n";
					request_stream << "Host: " << m_ip << "\r\n";
					request_stream << "User-Agent: C/1.0";
					request_stream << "Content-Type: application/x-www-form-urlencoded\r\n";
					request_stream << "Accept: */*\r\n";
					request_stream << "Content-Length: " << m_post_data.length() << "\r\n";
					request_stream << "Connection: close\r\n\r\n";
					request_stream << m_post_data;
				}
				// Attempt a connection to each endpoint in the list until we
				// successfully establish a connection.

				// 비동기로 소켓을 열도록 요청
				boost::asio::async_connect(m_socket, endpoint_iterator, boost::bind(&http_client::handle_connect, this, this->shared_from_this(), boost::asio::placeholders::error));

				//std::string strMessage = "http_client::handle_resolve()";
				//httpSystem.response_content(client->m_dummy, strMessage, m_fp_result);
			}
			else
			{
				LOG(INFO) << err.message();
				//httpSystem.response_content(client->m_dummy, err.message(), m_fp_result);
			}
		}

		void http_client::handle_connect(boost::shared_ptr< http_client > client, const boost::system::error_code& err)
		{
			if (!err)
			{
				// The connection was successful. Send the request.

				// 해당 소켓에 http 요청을 보낸다.
				boost::asio::async_write(m_socket, m_request, boost::bind(&http_client::handle_write_request, this, this->shared_from_this(), boost::asio::placeholders::error));

				std::string strMessage = "http_client::handle_connect()";
				//httpSystem.response_content(client->m_dummy, strMessage, m_fp_result);
			}
			else
			{
				LOG(INFO) << err.message();
				//httpSystem.response_content(client->m_dummy, err.message(), m_fp_result);
			}
		}

		void http_client::handle_write_request(boost::shared_ptr< http_client > client, const boost::system::error_code& err)
		{
			if (!err)
			{
				// Read the response status line. The response_ streambuf will
				// automatically grow to accommodate the entire line. The growth may be
				// limited by passing a maximum size to the streambuf constructor.

				// 요청 성공
				// 응답 상태를 파싱
				boost::asio::async_read_until(m_socket, m_response, "\r\n", boost::bind(&http_client::handle_read_status_line, this, this->shared_from_this(), boost::asio::placeholders::error));

				std::string strMessage = "http_client::handle_write_request()";
				//httpSystem.response_content(client->m_dummy, strMessage, m_fp_result);
				LOG(INFO) << strMessage;
			}
			else
			{
				LOG(INFO) << err.message();
				//httpSystem.response_content(client->m_dummy, err.message(), m_fp_result);
			}
		}

		void http_client::handle_read_status_line(boost::shared_ptr< http_client > client, const boost::system::error_code& err)
		{
			if (!err)
			{
				// Check that response is OK.

				// 응답이 제대로 도착했다면
				// in stream 을 하나 생성해서 스트림 버퍼와 연결
				std::istream response_stream(&m_response);

				// http 버전 파싱
				std::string http_version;
				response_stream >> http_version;

				// 상태 파싱
				unsigned int status_code;
				response_stream >> status_code;

				// 상태 메세지 파싱
				std::string status_message;
				std::getline(response_stream, status_message);
				if (!response_stream || http_version.substr(0, 5) != "HTTP/")
				{
					std::string strMessage = "Invalid response";
					//httpSystem.response_content(client->m_dummy, strMessage, m_fp_result);
					LOG(ERROR) << strMessage;
					return;
				}
				if (status_code != 200)
				{
					std::cout << " ";
					std::cout << status_code << "\n";

					std::string strMessage = "Response returned with status code ";
					std::string strStatusCode = boost::lexical_cast<std::string>(status_code);

					strMessage = strMessage + strStatusCode;
					LOG(ERROR) << strMessage;
					//httpSystem.response_content(client->m_dummy, strMessage, m_fp_result);

					return;
				}

				// Read the response headers, which are terminated by a blank line.

				// "\r\n\r\n" 을 받을때까지 파씽
				boost::asio::async_read_until(m_socket, m_response, "\r\n\r\n", boost::bind(&http_client::handle_read_headers, this, this->shared_from_this(), boost::asio::placeholders::error));

				//httpSystem.response_content( "http_client::handle_read_status_line() " + err.message(), m_fp_result );
				
				std::string strMessage = "http_client::handle_read_status_line()";
				//httpSystem.response_content(client->m_dummy, strMessage, m_fp_result);
				//LOG(INFO) << strMessage;
			}
			else
			{
				LOG(ERROR) << err.message();
				//httpSystem.response_content(client->m_dummy, err.message(), m_fp_result);
			}
		}

		void http_client::handle_read_headers(boost::shared_ptr< http_client > client, const boost::system::error_code& err)
		{
			if (!err)
			{
				// Process the response headers.
				std::istream response_stream(&m_response);
				
				std::string header;
				while (std::getline(response_stream, header) && header != "\r")
					std::cout << header << "\n";
				std::cout << "\n";


				m_vtResponseData.resize(m_response.size());
				buffer_copy(boost::asio::buffer(m_vtResponseData), m_response.data());
				// Write whatever content we already have to output.
				
				

				/*std::string content="";
				while (std::getline(response_stream, content))
					m_content.append(content);*/
				
				// Start reading remaining data until EOF.
				// 남은 데이터를 끝까지 읽어온다.
				boost::asio::async_read(m_socket, m_response, boost::asio::transfer_at_least(1), boost::bind(&http_client::handle_read_content, this, this->shared_from_this(), boost::asio::placeholders::error));

				std::string strMessage = "http_client::handle_read_headers()";
				
				LOG(INFO) << strMessage;
			}
			else
			{

				LOG(INFO) << err.message();
			}
		}

		void http_client::handle_read_content(boost::shared_ptr< http_client > client, const boost::system::error_code& err)
		{
			if (!err)
			{
				std::istream response_stream(&m_response);
				
				//if (m_response.size() > 0)
				//{
				//	std::cout << &m_response;
				//					
				//	response_stream >> m_content;
				//	//std::string received = is.get();
				//	//std::getline( is, content)
				//}
				/*std::string content = "";
				while (std::getline(response_stream, content))
					m_content.append(content);*/
				
				m_vtResponseData.resize(m_response.size());
				buffer_copy(boost::asio::buffer(m_vtResponseData), m_response.data());

			/*	istream_iterator<unsigned char> cin_it(response_stream);
				istream_iterator<unsigned char> eos;
				
				for_each(cin_it, eos, [&](unsigned char ch) {
					m_vtResponseData.push_back(ch);

					});*/
				
				// 데이터의 끝까지 계속 읽어온다.
				boost::asio::async_read(m_socket, m_response, boost::asio::transfer_at_least(1), boost::bind(&http_client::handle_read_content, this, this->shared_from_this(), boost::asio::placeholders::error));

				std::string strMessage = "http_client::handle_read_content()";
				LOG(INFO) << strMessage;
				//httpSystem.response_content(client->m_dummy, strMessage, m_fp_result);
			}
			else if (err == boost::asio::error::eof)
			{
				
				httpManager.response_content(client->m_dummy, m_vtResponseData, m_fp_result);
			}
			else if (err != boost::asio::error::eof)
			{
				LOG(INFO) << err.message();
				
				//httpManager.response_content(client->m_dummy, err.message(), m_fp_result);
			}
		}

	

} // namespace mir3d


#endif