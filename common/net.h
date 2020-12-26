#pragma once

#include "3rdparty/asio/asio.hpp"

namespace mana {

namespace net {

using Port = unsigned short;

using IoContext = asio::io_context;
using ErrorCode = asio::error_code;

using IpAddress = asio::ip::address;
using IpAddressV4 = asio::ip::address_v4;
using IpAddressV6 = asio::ip::address_v6;

using TcpAcceptor = asio::ip::tcp::acceptor;
using TcpEndpoint = asio::ip::tcp::endpoint;
using TcpIoStream = asio::ip::tcp::iostream;
using TcpResolver = asio::ip::tcp::resolver;
using TcpSocket = asio::ip::tcp::socket;

using UdpEndpoint = asio::ip::tcp::endpoint;
using UdpResolver = asio::ip::udp::resolver;
using UdpSocket = asio::ip::udp::socket;

using ConstBuffer = asio::const_buffer;
using MutableBuffer = asio::mutable_buffer;
using StreamBuf = asio::streambuf;

using SystemTimer = asio::system_timer;
using SteadyTimer = asio::steady_timer;


template <typename... Args>
inline decltype(auto) MakeAddress(Args &&... args) {
  return asio::ip::make_address(std::forward<Args &&>(args)...);
}

template <typename... Args>
inline decltype(auto) MakeTcpEndpoint(Port port, Args &&... addr_str) {
  return TcpEndpoint{MakeAddress(std::forward<Args &&>(addr_str)...), port};
}

}  // namespace nets

}  // namespace mana