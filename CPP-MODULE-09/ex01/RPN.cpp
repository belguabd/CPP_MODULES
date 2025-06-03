#include "RPN.hpp"

bool isValidExpression(const std::string &str)
{
    const std::string allowed = "0123456789+-*/";
    return str.find_first_not_of(allowed) == std::string::npos;
}

void printVector(const std::list<std::string> &vec)
{
    std::cout << "[";
    std::list<std::string>::const_iterator it = vec.begin();
    while (it != vec.end())
    {
        std::cout << *it;
        ++it;
        if (it != vec.end())
            std::cout << ", ";
    }
    std::cout << "]\n";
}
void RPN::RPNCalculator()
{
    double push;
    double rpnFirst;
    double rpnSecond;
    char op;

    std::list<std::string>::iterator it = numbers.begin();

    for (; it != numbers.end(); it++)
    {
        std::string arg = *it;
        if (std::isdigit(arg[0]))
        {
            std::stringstream ss(*it);
            int number;
            ss >> number;
            st.push(number);
        }
        else
        {
            op = arg[0];
            if (st.size() < 2)
                throw std::invalid_argument("Not enough operands in stack for operation");
            rpnSecond = st.top();
            st.pop();
            rpnFirst = st.top();
            st.pop();
            if (op == '+')
                push = rpnFirst + rpnSecond;
            else if (op == '-')
                push = rpnFirst - rpnSecond;
            else if (op == '*')
                push = rpnFirst * rpnSecond;
            else if (op == '/')
            {
                if (rpnSecond == 0)
                    throw std::invalid_argument("Divided by zero!!");
                push = rpnFirst / rpnSecond;
            }
            if (push > INT_MAX || push < INT_MIN)
                throw std::overflow_error("Overflow error: result out of int range");
            st.push(push);
        }
    }
    if (st.size() != 1)
        throw std::invalid_argument("Invalid RPN expression");
    std::cout << st.top() << "\n";
}
void RPN::parseArgs()
{
    std::istringstream ss(rpn);
    std::string token;
    while (ss >> token)
    {
        numbers.push_back(token);
        if (!isValidExpression(token) || token.length() > 1)
            throw std::runtime_error("Invalid: contains other characters");
    }
}

void RPN::main(int argc, char *av[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << av[0] << " <RPN expression>\n";
        return;
    }
    try
    {

        this->rpn = av[1];
        parseArgs();
        RPNCalculator();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }
}

RPN::RPN() {}
RPN::RPN(const RPN &other)
    : st(other.st), rpn(other.rpn), numbers(other.numbers) {}
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        st = other.st;
        rpn = other.rpn;
        numbers = other.numbers;
    }
    return *this;
}
RPN::~RPN() {}