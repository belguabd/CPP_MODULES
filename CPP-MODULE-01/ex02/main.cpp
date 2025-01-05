#include <iostream>

int main()
{

    std::string A = "HI THIS IS BRAIN";
    
    std::string *stringPTR = &A;
    std::string &stringREF = A;
    std::cout << "Memory Address of A : " << &A << std::endl;
    std::cout << "Memory Address of stringPTR : " << stringPTR << std::endl;
    std::cout << "Memory Address of stringREF : " << &stringREF << std::endl;

    std::cout << "Value of the string : " << A << std::endl;
    std::cout << "Value of stringPTR : " << *stringPTR << std::endl;
    std::cout << "Value of stringREF : " << stringREF << std::endl;
}