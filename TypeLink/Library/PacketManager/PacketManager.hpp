#ifndef PACKETMANAGER_HPP_
#define PACKETMANAGER_HPP_

#include "Includes.hpp"
#include "Console.hpp"
#include "Connection.hpp"

namespace TypeLink {
    class PacketManager {
        protected:
            std::shared_ptr<Console> _console;
        public:
            PacketManager();
            PacketManager(std::shared_ptr<Console> console);
            ~PacketManager();
            std::shared_ptr<Packet> createPacket(void *data, ssize_t size);
            void *extractData(std::shared_ptr<Packet> packet);
            void printInfoPacket(std::shared_ptr<Packet> packet);
    };
} // namespace TypeLink

#endif /* !PACKETMANAGER_HPP_ */