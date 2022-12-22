/*
** File: main.cpp
** Project: Client
** File Created: 8th March 2023
** Author: Parumezan
** Copyright (c) 2023 JB
*/

#include <signal.h>
#include "Client.hpp"
#include "PacketManager.hpp"

TYPELINK_CONSOLE(false)
TYPELINK_CLIENT
TYPELINK_PACKET_MANAGER

void signalHandler(int signum)
{
    std::cout << std::endl;
    std::cout << "Interrupt signal (" << signum << ") received." << std::endl;
    std::cout << "Closing server..." << std::endl;
    exit(signum);
}

int main(int ac, char **av)
{
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);

    if (ac != 4) {
        std::cerr << "Usage: <ipAddress> <portTcp> <portUcp>" << std::endl;
        return 1;
    }

    client = std::make_shared<TypeLink::Client>(av[1], std::stoi(av[2]), std::stoi(av[3]), console);
    client->connectTcpSocket();

    while (true) {
        std::string input;
        std::getline(std::cin, input);
        input.resize(input.size() + 1);
        input[input.size() - 1] = '\0';
        std::shared_ptr<TypeLink::Packet> packet = packetManager->createPacket((void *)input.c_str(), input.size() + 1);
        // packetManager->printInfoPacket(packet);
        client->sendTcpPacket(packet);

        // packetManager->printInfoPacket(packet);
        client->sendUdpPacket(packet);

        std::shared_ptr<TypeLink::Packet> packetRecv = nullptr;
        try {
            packetRecv = client->recvTcpPacket();
            if (packetRecv != nullptr) {
                // packetManager->printInfoPacket(packetRecv);
                void *data = packetManager->extractData(packetRecv);
                std::cout << "Data: " << static_cast<char *>(data) << std::endl;
            }
        } catch (std::exception &error) {
            std::cout << error.what() << std::endl;
            break;
        }
    }
    return 0;
}