/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:02:45 by ademaill          #+#    #+#             */
/*   Updated: 2025/03/21 11:49:54 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool ValidDate(const std::string& date);
static bool ValidValue(const std::string& date);

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(const std::string &database_file)
{
	std::ifstream	db_file(database_file);
	if (!db_file.is_open())
	{
		std::cerr << "Error, could not open file : " << database_file << std::endl;
	}

	std::string line;
	std::getline(db_file, line);
	while (std::getline(db_file, line))
	{
		std::string key = line.substr(0, line.find(','));
		std::string value = line.substr(line.find(',') + 1);
		this->_dataBase.insert(std::make_pair(key, std::stof(value)));
	}
	db_file.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
		_dataBase = src._dataBase;
	return *this;
}

void	BitcoinExchange::showDatabase() const
{
	std::cout << "___ DATA BASE ___" << std::endl;
	std::map<std::string, float>::const_iterator it = this->_dataBase.begin();
	while (it != this->_dataBase.end())
	{
		std::cout << "{" << it->first << "} => " << it->second << std::endl;
		it++;
	}
	std::cout << std::endl;
}

void	BitcoinExchange::displayFromFile(const std::string &filename) const
{
	std::ifstream	file(filename);
	if (!file.is_open())
	{
		std::cerr << "Error, could not open file : " << filename << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.find('|') == std::string::npos)
		{
			std::cout << "Error '|' not found at line : " << line << std::endl;
			continue;
		}

		line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
		std::string date = line.substr(0, line.find('|'));
		std::string value = line.substr(line.find('|') + 1);

		if(!ValidDate(date))
		{
			std::cout << "=> {" << date << "}" << std::endl;
			continue;
		}
		if(!ValidValue(value))
		{
			std::cout << "=> {" << value << "}" << std::endl;
			continue;
		}

		float	exchangeRate = this->getExchangeRate(date);
		if (exchangeRate == -1)
		{
			std::cout << "Error, no exhange rate found for '" << date << "'" << std::endl;
			continue;
		}
		std::cout << date << " => " << value << " = " << exchangeRate * std::stof(value) << std::endl;
	}
}

float	BitcoinExchange::getExchangeRate(const std::string &date) const
{
	std::map<std::string, float>::const_iterator it = this->_dataBase.find(date);
	if(it == this->_dataBase.end())
	{
		std::map<std::string, float>::const_iterator ite = this->_dataBase.lower_bound(date);
		if (ite != this->_dataBase.begin())
		{
			ite--;
			return ite->second;
		}
		return -1;
	}
	return it->second;
}

static bool	ValidDate(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error, date format must be YYYY-MM-DD" << std::endl;
		return false;
	}
	std::string strYear = date.substr(0, 4);
	std::string strMonth = date.substr(5, 2);
	std::string strDay = date.substr(8, 2);
	if(strYear.find_first_not_of("0123456789") != std::string::npos || strMonth.find_first_not_of("0123456789") != std::string::npos || strDay.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Years, Month and day must be numeric";
		return false;
	}
	int year = std::stoi(strYear);
	int month = std::stoi(strMonth);
	int day = std::stoi(strDay);
	if (year < 0 || month < 1 || month > 12 || day < 1)
		return false;
	
	int maxday;
	switch (month)
	{
		case 2:
			maxday = 28;
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 != 0))
				maxday = 29;
			break;
		case 4 : case 6 : case 9 : case 11 : maxday = 30;
			break;
		default:
			maxday = 31;
			break;
	}
	return day <= maxday;
}

static bool ValidValue(const std::string &value)
{
	if (value.length() == 0)
	{
		std::cout << "Error, value is empty" << std::endl;
		return false;
	}
	if (value.find_first_not_of("0123456789.-") != std::string::npos)
	{
		std::cout << "Error, value is not a number" << std::endl;
		return false;
	}
	if (std::count(value.begin(), value.end(), '.') > 1)
	{
		std::cout << "Error, value must have only one '.'";
		return false;
	}
	if (std::count(value.begin(), value.end(), '-') > 1)
	{
		std::cout << "Error, value must have only one '-'";
		return false;
	}
	if (value[0] == '.' || value[value.length() - 1] == '.')
	{
		std::cout << "Error, '.' can't be the first or the last character" << std::endl;
	}
	if (std::count(value.begin(), value.end(), '-') == 1)
	{
		if (value[0] != '-')
		{
			std::cout << "Error, '-' must be the first character" << std::endl;
			return false;
		}
	}
	if (std::stod(value) < 0 || std::stod(value) > 1000)
	{
		std::cout << "Error, value must be between 0 and 1000 ";
		return false;
	}
	return true;
}