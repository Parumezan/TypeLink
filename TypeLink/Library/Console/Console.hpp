#ifndef CONSOLE_HPP_
#define CONSOLE_HPP_

#include "Includes.hpp"
#include "Exception.hpp"

namespace TypeLink
{
    class Console
    {
        private:
            bool _isQuiet;
            ssize_t _info;
            ssize_t _warn;
            ssize_t _error;
            std::vector<std::string> _history;
            std::unique_ptr<Exception> _exception;
            void print(ConsoleType type, std::string const &msg);
            std::string getLocalTime();
            void putHistory(std::string const &msg);

        public:
            Console();
            Console(bool isQuiet);
            ~Console();
            void info(std::string const &msg);
            void warn(std::string const &msg);
            void error(std::string const &msg);
            Exception throwException(std::string const &msg);
    };
} // namespace TypeLink

#endif /* !CONSOLE_HPP_ */