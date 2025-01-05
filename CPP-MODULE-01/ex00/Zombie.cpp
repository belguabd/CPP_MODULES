#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
std::string Zombie::getName()
{
    return (name);
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie::Zombie() : name("Zombie") {}

Zombie::~Zombie()
{
    std::cout << "Destructed: " << name << std::endl;
}
