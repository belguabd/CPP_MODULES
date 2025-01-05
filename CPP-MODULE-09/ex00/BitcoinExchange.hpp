/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:39:37 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/23 16:17:19 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

#define TRUE 1
#define FALSE 0

class BitcoinExchange
{
public:
    void readDataFromFile(const std::string &file);
    void setMap(const std::string &av);

private:
    std::map<std::string, double> dateValueMap;
    std::map<std::string, double> dateValueMapIn;
    std::vector<std::string> parsedData;
    void parse_data(const std::string &line);
    int ft_atoi(const std::string &string);
};
