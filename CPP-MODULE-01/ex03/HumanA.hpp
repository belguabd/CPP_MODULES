
#include "Weapon.hpp"

class HumanA
{

public:
	HumanA(std::string newName, Weapon &newWeapon);
	void attack();

private:
	std::string name;
	Weapon &weapon;
};
