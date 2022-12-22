#include "Network.hpp"

using namespace TypeLink;

Network::Network(std::shared_ptr<Console> console)
{
    this->_console = console;
    this->_sock = 0;
    this->_sin.sin_family = AF_INET;
    this->_sin.sin_addr.s_addr = INADDR_ANY;
    this->_sin.sin_port = htons(0);
    FD_ZERO(&this->_rdfd);
    FD_ZERO(&this->_wdfd);
}

Network::~Network()
{
    this->closeSocket();
}

void Network::closeSocket()
{
    close(this->_sock);
}

void Network::resetSocket()
{
    FD_ZERO(&this->_rdfd);
    FD_ZERO(&this->_wdfd);
}

void Network::setSocket(int sock)
{
    this->_sock = sock;
}

void Network::tcpSendPacket(int sock, std::shared_ptr<Packet> data)
{
    uint8_t buffer[BUFFER_SIZE] = {0};
    ssize_t sizeSend = 0;
    std::string clientInterrupted = "Send packet failed: client interrupted";

    if (data->header.size > BUFFER_SIZE)
        throw this->_console->throwException("Send packet failed: size is too big");
    std::copy(reinterpret_cast<uint8_t *>(&data->header), reinterpret_cast<uint8_t *>(&data->header) + sizeof(PacketHeader), buffer);
    std::copy(data->data.begin(), data->data.end(), buffer + sizeof(PacketHeader));
    buffer[sizeof(PacketHeader) + data->header.size] = data->magicEOF;
    if ((sizeSend = send(sock, buffer, sizeof(PacketHeader) + data->header.size + sizeof(uint8_t), 0)) <= 0)
        throw this->_console->throwException(clientInterrupted);
    this->_console->info("Tcp packet sent");
}

void Network::udpSendPacket(int sock, std::shared_ptr<Packet> data)
{
    uint8_t buffer[BUFFER_SIZE] = {0};
    ssize_t sizeSend = 0;
    std::string clientInterrupted = "Send packet failed: client interrupted";

    if (data->header.size > BUFFER_SIZE)
        throw this->_console->throwException("Send packet failed: size is too big");
    std::copy(reinterpret_cast<uint8_t *>(&data->header), reinterpret_cast<uint8_t *>(&data->header) + sizeof(PacketHeader), buffer);
    std::copy(data->data.begin(), data->data.end(), buffer + sizeof(PacketHeader));
    buffer[sizeof(PacketHeader) + data->header.size] = data->magicEOF;
    if ((sizeSend = sendto(sock, buffer, sizeof(PacketHeader) + data->header.size + sizeof(uint8_t), 0, reinterpret_cast<struct sockaddr *>(&this->_sin), sizeof(this->_sin))) <= 0)
        throw this->_console->throwException(clientInterrupted);
    this->_console->info("Udp packet sent");
}

std::shared_ptr<Packet> Network::tcpReceivePacket(int sock)
{
    std::shared_ptr<Packet> packet = std::make_shared<Packet>();
    uint8_t buffer[sizeof(PacketHeader) + BUFFER_SIZE + sizeof(uint8_t)] = {0};
    ssize_t sizeRead = 0;
    std::string clientInterrupted = "Recv packet failed: client interrupted";

    if ((sizeRead = recv(sock, buffer, sizeof(PacketHeader) + BUFFER_SIZE + sizeof(uint8_t), 0)) <= 0)
        throw this->_console->throwException(clientInterrupted);
    packet->header = *reinterpret_cast<PacketHeader *>(buffer);
    if (packet->header.magic != MAGIC_NUMBER)
        throw this->_console->throwException("Recv packet failed: magic is wrong");
    if (packet->header.size > BUFFER_SIZE)
        throw this->_console->throwException("Recv packet failed: size is too big");
    packet->data = std::vector<uint8_t>(buffer + sizeof(PacketHeader), buffer + sizeof(PacketHeader) + packet->header.size);
    packet->magicEOF = buffer[sizeof(PacketHeader) + packet->header.size];
    if (packet->magicEOF != MAGIC_EOF)
        throw this->_console->throwException("Recv packet failed: magic EOF is wrong");
    this->_console->info("Tcp packet received");
    return packet;
}

std::shared_ptr<Packet> Network::udpReceivePacket(int sock)
{
    std::shared_ptr<Packet> packet = std::make_shared<Packet>();
    uint8_t buffer[sizeof(PacketHeader) + BUFFER_SIZE + sizeof(uint8_t)] = {0};
    ssize_t sizeRead = 0;
    socklen_t sinSize = sizeof(this->_sin);
    std::string clientInterrupted = "Recv packet failed: client interrupted";

    if ((sizeRead = recvfrom(sock, buffer, sizeof(PacketHeader) + BUFFER_SIZE + sizeof(uint8_t), 0, reinterpret_cast<struct sockaddr *>(&this->_sin), &sinSize)) <= 0)
        throw this->_console->throwException(clientInterrupted);
    packet->header = *reinterpret_cast<PacketHeader *>(buffer);
    if (packet->header.magic != MAGIC_NUMBER)
        throw this->_console->throwException("Recv packet failed: magic is wrong");
    if (packet->header.size > BUFFER_SIZE)
        throw this->_console->throwException("Recv packet failed: size is too big");
    packet->data = std::vector<uint8_t>(buffer + sizeof(PacketHeader), buffer + sizeof(PacketHeader) + packet->header.size);
    packet->magicEOF = buffer[sizeof(PacketHeader) + packet->header.size];
    if (packet->magicEOF != MAGIC_EOF)
        throw this->_console->throwException("Recv packet failed: magic EOF is wrong");
    this->_console->info("Udp packet received");
    return packet;
}