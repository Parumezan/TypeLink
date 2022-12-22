/*
** File: main.cpp
** Project: Server
** File Created: 7th March 2023
** Author: Parumezan
** Copyright (c) 2023 JB
*/

#include <signal.h>
#include <string.h>
#include "Server.hpp"
#include "PacketManager.hpp"

TYPELINK_CONSOLE(false)
TYPELINK_SERVER
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
        std::cerr << "Usage: <portTcp> <portUcp> <max_clients>" << std::endl;
        return 1;
    }

    server = std::make_shared<TypeLink::Server>(std::stoi(av[1]), std::stoi(av[2]), std::stoi(av[3]), console);

    while (true) {
        server->acceptTcpConnection();
        for (auto &connection : *server->getTcpConnections()) {
            try {
                std::shared_ptr<TypeLink::Packet> packet = server->recvTcpPacketFrom(connection->getSocket());
                if (packet != nullptr) {
                    // packetManager->printInfoPacket(packet);
                    void *data = packetManager->extractData(packet);
                    std::cout << "Data: " << static_cast<char *>(data) << std::endl;
                }
            } catch (std::exception &error) {
                std::cerr << error.what() << std::endl;
                server->removeTcpConnection(connection->getSocket());
                break;
            }
        }
        try {
            std::shared_ptr<TypeLink::Packet> packet = server->recvUdpPacket();
            if (packet != nullptr) {
                // packetManager->printInfoPacket(packet);
                void *data = packetManager->extractData(packet);
                std::cout << "Data: " << static_cast<char *>(data) << std::endl;
                if (strcmp(static_cast<char *>(data), "Hello") == 0) {
                    server->sendTcpPacketToAll(packetManager->createPacket((void *)"DAMN!\n", 6));
                }
            }
        } catch (std::exception &error) {
            std::cerr << error.what() << std::endl;
        }
        sleep(0.1);
    }
    return 0;
}