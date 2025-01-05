#include "Zombie.hpp"

int main()
{

    randomChump("HELLO WORLD");
    
    Zombie *test;
    test = newZombie("42");
    test->announce();
    delete test;
}
