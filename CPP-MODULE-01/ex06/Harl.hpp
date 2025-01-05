#include <iostream>

class Harl
{

public:
    void complain(std::string level);
    enum Level
    {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        UNKNOWN
    };

private:
    void printDebug(void);
    void printInfo(void);
    void printWarning(void);
    void printError(void);
    void printDefault(void);
};