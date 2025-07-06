#ifndef PACKETSENDER_HPP
#define PACKETSENDER_HPP

#include <string>

class PacketSender {
public:
  PacketSender();
  void sendWOL();

private:
  unsigned char mac[6];
  unsigned char packet[102];

  static constexpr int PORT = 9;
  static const std::string IP;
};

#endif // !PACKETSENDER_HPP
