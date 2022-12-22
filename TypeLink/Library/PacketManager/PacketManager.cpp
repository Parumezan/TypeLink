#include "PacketManager.hpp"

using namespace TypeLink;

PacketManager::PacketManager()
{
    this->_console = std::make_shared<Console>();
}

PacketManager::PacketManager(std::shared_ptr<Console> console)
{
    this->_console = console;
}

PacketManager::~PacketManager()
{
}

std::shared_ptr<Packet> PacketManager::createPacket(void *data, ssize_t size)
{
    std::shared_ptr<Packet> packet = std::make_shared<Packet>();

    packet->header.magic = MAGIC_NUMBER;
    packet->header.type = PacketType::DATA;
    packet->header.size = size;
    packet->data = std::vector<uint8_t>(reinterpret_cast<uint8_t *>(data), reinterpret_cast<uint8_t *>(data) + size);
    packet->magicEOF = MAGIC_EOF;
    this->_console->info("PacketManager: Packet created");
    return packet;
}

void *PacketManager::extractData(std::shared_ptr<Packet> packet)
{
    void *data = nullptr;

    if (packet->header.magic != MAGIC_NUMBER || packet->magicEOF != MAGIC_EOF) {
        this->_console->error("PacketManager: Packet is not valid");
        return nullptr;
    }
    data = reinterpret_cast<void *>(packet->data.data());
    this->_console->info("PacketManager: Data extracted");
    return data;
}

void PacketManager::printInfoPacket(std::shared_ptr<Packet> packet)
{
    std::string ip = std::to_string(packet->header.ip[0]) + "." + std::to_string(packet->header.ip[1]) + "." + std::to_string(packet->header.ip[2]) + "." + std::to_string(packet->header.ip[3]);
    std::string port = std::to_string(packet->header.port);
    std::string size = std::to_string(packet->header.size);
    std::string type = std::to_string(packet->header.type);
    std::string data = "";

    for (auto &byte : packet->data)
        data += std::to_string(byte);
    std::cout << "Packet Info:" << std::endl;
    std::cout << "Ip " << ip << std::endl;
    std::cout << "Port " << port << std::endl;
    std::cout << "Size " << size << std::endl;
    std::cout << "Type " << type << std::endl;
    std::cout << "Data " << data << std::endl;
    this->_console->info("PacketManager: Packet info printed");
}