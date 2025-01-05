#include "Harl.hpp"

void Harl::printDebug(void)
{
    std::cout << "[ DEBUG ] This is a debug message." << std::endl;
}

void Harl::printInfo(void)
{
    std::cout << "[ INFO ] This is an info message." << std::endl;
}

void Harl::printWarning(void)
{
    std::cout << "[ WARNING ] This is a warning message." << std::endl;
}

void Harl::printError(void)
{
    std::cout << "[ ERROR ] This is an error message." << std::endl;
}
void Harl::printDefault(void)
{
    std::cout << "This is an unknown message." << std::endl;
}

void Harl::complain(std::string level)
{
    int levelCase;
    int i;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    i = 0;
    while (levels[i] != level)
        i++;
    switch (i)
    {
        case DEBUG:
            printDebug();
        case INFO:
            printInfo();
        case WARNING:
            printWarning();
        case ERROR:
            printError();
            break;
        default:
            printDefault();
    }
}