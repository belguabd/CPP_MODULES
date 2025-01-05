#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
    Zombie();
    void announce(void);
    void setName(std::string name);
    std::string getName(void);
    ~Zombie();

private:
    std::string name;
};
void randomChump(std::string name);
Zombie *newZombie(std::string name);
#endif      