#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <limits.h>
#include <list>
#include <stack>

#include <sstream> 

class RPN
{
    private:
        std::stack<int>             st;
        std::string                 rpn;
        std::list<std::string>      numbers;
    public:
        void                        main(int argc, char *av[]);
        void                        parseArgs();
        void                        RPNCalculator();

                                    RPN();
                                    RPN(const RPN &other);
                                    RPN &operator=(const RPN &other); 
                                    ~RPN();

};


#endif // RPN_HPP