#include "Console.hpp"

using namespace TypeLink;

Console::Console()
{
    this->_isQuiet = true;
    this->_info = 0;
    this->_warn = 0;
    this->_error = 0;
}

Console::Console(bool isQuiet)
{
    this->_isQuiet = isQuiet;
    this->_info = 0;
    this->_warn = 0;
    this->_error = 0;
}

Console::~Console()
{
    if (!this->_isQuiet)
        std::cout << "TypeLink: " << this->_info << " info, " << this->_warn << " warn, " << this->_error << " error" << std::endl;
}

std::string Console::getLocalTime()
{
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);

    std::string hour = (ltm->tm_hour < 10) ? "0" + std::to_string(ltm->tm_hour) : std::to_string(ltm->tm_hour);
    std::string min = (ltm->tm_min < 10) ? "0" + std::to_string(ltm->tm_min) : std::to_string(ltm->tm_min);
    std::string sec = (ltm->tm_sec < 10) ? "0" + std::to_string(ltm->tm_sec) : std::to_string(ltm->tm_sec);
    return hour + ":" + min + ":" + sec;
}

void Console::info(std::string const &msg)
{
    this->_info++;
    std::string info = this->getLocalTime() + " TL-Info: " + msg;
    this->putHistory(info);

    if (!this->_isQuiet)
        this->print(ConsoleType::INFO, msg);
}

void Console::warn(std::string const &msg)
{
    this->_warn++;
    std::string warn = this->getLocalTime() + " TL-Warn: " + msg;
    this->putHistory(warn);

    if (!this->_isQuiet)
        this->print(ConsoleType::WARN, msg);
}

void Console::error(std::string const &msg)
{
    this->_error++;
    std::string error = this->getLocalTime() + " TL-Error: " + msg;
    this->putHistory(error);

    if (!this->_isQuiet)
        this->print(ConsoleType::ERROR, msg);
}

Exception Console::throwException(std::string const &msg)
{
    this->error(msg);
    this->_exception = std::make_unique<Exception>(msg);
    return *this->_exception;
}

void Console::print(ConsoleType type, std::string const &msg)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (type) {
    case ConsoleType::INFO:
        SetConsoleTextAttribute(hConsole, 10);
        std::cout << this->getLocalTime() + " TL-Info: " << msg << std::endl;
        break;
    case ConsoleType::WARN:
        SetConsoleTextAttribute(hConsole, 14);
        std::cout << this->getLocalTime() + " TL-Warn: " << msg << std::endl;
        break;
    case ConsoleType::ERROR:
        SetConsoleTextAttribute(hConsole, 12);
        std::cerr << this->getLocalTime() + " TL-Error: " << msg << std::endl;
        break;
    }
    SetConsoleTextAttribute(hConsole, 15);
#else
    switch (type) {
    case ConsoleType::INFO:
        std::cout << this->getLocalTime() + " TL-Info: "
                  << "\033[32m" << msg << "\033[0m" << std::endl;
        break;
    case ConsoleType::WARN:
        std::cout << this->getLocalTime() + " TL-Warn: "
                  << "\033[33m" << msg << "\033[0m" << std::endl;
        break;
    case ConsoleType::ERROR:
        std::cerr << this->getLocalTime() + " TL-Error: "
                  << "\033[31m" << msg << "\033[0m" << std::endl;
        break;
    }
#endif
}

void Console::putHistory(std::string const &msg)
{
    if (this->_history.size() > HISTORY_SIZE) {
        this->_history.erase(this->_history.begin());
        this->_history.push_back(msg);
    } else {
        this->_history.push_back(msg);
    }
}