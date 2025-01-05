/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:16:20 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/30 10:32:49 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
        *this = other;
    return *this;
}
ScalarConverter::~ScalarConverter()
{
}

static int parse_input(const std::string &data)
{
    if (data.empty())
        std::cout << "Error in your input!!\n", std::exit(1);
    if (data.size() > 1 && std::isalpha(data[0]))
        std::cout << "Error in your input!!\n", std::exit(1);

    for (size_t i = 1; data[i]; i++)
    {
        if ((std::isalpha(data[i]) && data[i] != 'f') ||
            (data[i] == 'f' && data[i + 1]) ||
            isspace(data[i]))
        {
            std::cout << "Error in your input!!\n", std::exit(1);
        }
    }
    return (0);
}
static long double ft_atoi(const std::string &data)
{
    long double num;

    std::size_t pos = data.find('f', 0);
    if (pos != std::string::npos)
        std::stringstream(data.substr(0, pos)) >> num;
    else
        std::stringstream(data) >> num;
    return num;
}

bool special(std::string data)
{
    return (data == "-inff" ||
            data == "+inff" ||
            data == "nanf" ||
            data == "-inf" ||
            data == "+inf" ||
            data == "nan");
}

void checkSpecial(std::string data)
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    if (data != "nanf" && data != "nan")
    {
        std::cout << "float: "
                  << ((data == "-inf" || data == "+inf") ? data + "f" : data)
                  << "\n";
        std::cout << "double: "
                  << ((data == "-inff" || data == "+inff") ? data.substr(0, 4) : data)
                  << "\n";
    }
    else
    {
        std::cout << "float: " << ((data == "nan") ? data + "f" : data) << "\n";
        std::cout << "double: " << ((data == "nanf") ? data.substr(0, 3) : data) << "\n";
    }
    std::exit(0);
}

void ScalarConverter::convert(const std::string &data)
{

    if (special(data))
        checkSpecial(data);
    parse_input(data);
    long double num = ft_atoi(data);
    if (std::isalpha(data[0]))
        num = data[0];

    if (data.size() == 1 && std::isprint(data[0]))
        num = static_cast<int>(data[0]);
    char char_value = static_cast<char>(num);
    int int_value = static_cast<int>(num);
    double double_value = static_cast<double>(num);
    float float_value = static_cast<float>(num);

    if (num < 0)
        std::cout << "char: impossible\n";
    else if (std::isprint(char_value))
        std::cout << "char: '" << char_value << "'" << std::endl;
    else
        std::cout << "char: " << "Non displayable" << std::endl;

    std::cout << "int: " << int_value << std::endl;
    std::cout << "float: " << float_value << (std::floor(num) == num ? ".0f" : "f") << std::endl;
    std::cout << "double: " << double_value << (std::floor(num) == num ? ".0" : "") << std::endl;
};
