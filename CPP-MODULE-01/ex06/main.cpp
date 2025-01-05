#include "Harl.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./harlFilter level" << std::endl;
        return (1);
    }
    Harl H;
    std::string arg;

    arg = av[1];
    H.complain(arg);
}