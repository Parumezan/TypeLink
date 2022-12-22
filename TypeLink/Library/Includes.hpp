#ifndef INCLUDES_HPP_
#define INCLUDES_HPP_

#ifdef _WIN32
    #include <windows.h>
#endif

#include <arpa/inet.h>
#include <deque>
#include <iostream>
#include <memory>
#include <mutex>
#include <netdb.h>
#include <netinet/in.h>
#include <queue>
#include <stdexcept>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

#define HISTORY_SIZE 2048
#define BUFFER_SIZE 1024
#define MAGIC_NUMBER 0x42
#define MAGIC_EOF 0x24

#define TYPELINK_CONSOLE(isQuiet) std::shared_ptr<TypeLink::Console> console = std::make_shared<TypeLink::Console>(isQuiet);
#define TYPELINK_SERVER std::shared_ptr<TypeLink::Server> server;
#define TYPELINK_CLIENT std::shared_ptr<TypeLink::Client> client;
#define TYPELINK_PACKET_MANAGER std::shared_ptr<TypeLink::PacketManager> packetManager = std::make_shared<TypeLink::PacketManager>(console);

namespace TypeLink
{
    enum ConsoleType {
        INFO,
        WARN,
        ERROR
    };

    enum PacketType {
        CONNECT,
        DISCONNECT,
        DATA,
        PING
    };

    typedef struct {
            uint8_t magic;
            PacketType type;
            uint16_t size;
            uint8_t ip[4];
            uint16_t port;
    } PacketHeader;

    typedef struct {
            PacketHeader header;
            std::vector<uint8_t> data;
            uint8_t magicEOF;
    } Packet;

    typedef struct {
            struct timeval timeoutRecvUdp;
            struct timeval timeoutSendUdp;
    } TimeoutUdp;

    typedef struct {
            struct timeval timeoutRecvTcp;
            struct timeval timeoutSendTcp;
    } TimeoutTcp;

    typedef struct {
            uint16_t portTcp;
            uint16_t portUdp;
            size_t maxConnections;
            TimeoutUdp timeoutUdp;
            TimeoutTcp timeoutTcp;
    } ServerInit;

    typedef struct {
            std::string ip;
            uint16_t portTcp;
            uint16_t portUdp;
            TimeoutUdp timeoutUdp;
            TimeoutTcp timeoutTcp;
    } ClientInit;
} // namespace TypeLink

#endif /* !INCLUDES_HPP_ */