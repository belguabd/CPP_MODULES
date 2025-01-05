
#include "Zombie.hpp"

int main()
{

    Zombie zombie;
    std::string name;
    int N;
    Zombie *test;

    N = 3;
    name = "Zombie";
    test = ZombieHorde(N, name);
    for (int i = 0; i < N; i++)
        test[i].announce();
    delete[] test;
}