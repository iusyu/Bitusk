#include <string>
#include <memory>

#include <boost/asio.hpp>


#pragma once


typedef std::basic_string<unsigned char> ustring;


// Network Socket Related
using namespace boost::asio;
typedef std::shared_ptr<ip::tcp::socket> socket_ptr; 
typedef ip::tcp::endpoint endpeer;
