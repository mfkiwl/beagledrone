#include <iostream>
#include "max21100.hpp"
#include <sstream>

#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

class udp_server
{
public:
  udp_server(boost::asio::io_service& io_service)
    : socket_(io_service, udp::endpoint(udp::v4(), 8080)), m()
  {
    start_receive();
  }
  
private:
  void start_receive()
  {
    socket_.async_receive_from(
			       boost::asio::buffer(recv_buffer_), remote_endpoint_,
			       boost::bind(&udp_server::handle_receive, this,
					   boost::asio::placeholders::error,
					   boost::asio::placeholders::bytes_transferred));
  }
  void handle_receive(const boost::system::error_code& error,
		      std::size_t /*bytes_transferred*/)
  {
    if (!error || error == boost::asio::error::message_size)
      {
	Orientation ao = m.getAccelXYZ();
	Orientation go = m.getGyroXYZ();
	
	std::stringstream ss;
	double scale = 65536;
	double ax = (((int16_t)ao.x*(4/scale)));
	double ay = (((int16_t)ao.y*(4/scale)));
	double az = (((int16_t)ao.z*(4/scale)));
	
	double gx = (((int16_t)go.x*(4/scale)));
	double gy = (((int16_t)go.y*(4/scale)));
	double gz = (((int16_t)go.z*(4/scale)));
	
	ss << ax << ":" << ay << ":" << az;
	ss << ":";
	ss << gx << ":" << gy << ":" << gz;
	
	boost::shared_ptr<std::string> message(new std::string(ss.str()));
	
	socket_.async_send_to(boost::asio::buffer(*message), remote_endpoint_,
			      boost::bind(&udp_server::handle_send, this, message,
					  boost::asio::placeholders::error,
					  boost::asio::placeholders::bytes_transferred));
	
	start_receive();
      }
  }
  
  void handle_send(boost::shared_ptr<std::string> /*message*/,
		   const boost::system::error_code& /*error*/,
		   std::size_t /*bytes_transferred*/)
  {
  }
  
  udp::socket socket_;
  udp::endpoint remote_endpoint_;
  boost::array<char, 1> recv_buffer_;
  max21100 m;
};

int main(int argc, char **args) {
  try
    {
      boost::asio::io_service io_service;
      udp_server server(io_service);
      io_service.run();
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  return 0;
}
