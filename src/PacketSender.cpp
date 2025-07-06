#include "PacketSender.hpp"
#include <arpa/inet.h>
#include <cstring>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

const std::string PacketSender::IP = "255.255.255.255";
PacketSender::PacketSender()
    : mac{0x60, 0xcf, 0x84, 0xde, 0x6b, 0x09}, packet{} {
  memset(packet, 0xFF, 6);
  for (int i = 0; i < 16; ++i) {
    memcpy(&packet[6 + i * 6], mac, 6);
  }
}

void PacketSender::sendWOL() {
  int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  int optval = 1;
  setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval));

  sockaddr_in address{};
  address.sin_family = AF_INET;
  address.sin_port = htons(PORT);
  address.sin_addr.s_addr = inet_addr(IP.c_str());

  sendto(sock, packet, sizeof(packet), 0, (sockaddr *)&address,
         sizeof(address));
  close(sock);
}
