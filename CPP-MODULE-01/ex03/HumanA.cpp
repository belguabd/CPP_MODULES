
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {};

void HumanA::attack()
{
    std::cout << name
              << " Attacks with their "
              << HumanA::weapon.getType()
              << std::endl;
}