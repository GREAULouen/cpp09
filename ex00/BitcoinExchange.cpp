/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:36:01 by lgreau            #+#    #+#             */
/*   Updated: 2024/06/11 17:35:19 by lgreau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream ifs("data.csv", std::ifstream::in);

	std::string	line;
	std::getline(ifs, line); // First line serves as header : "date,exchange_rate"
	size_t	comma = 0;
	while (std::getline(ifs, line))
	{
		comma = line.find(',', 0);
		// Add date validation
		if (this->_rates.find(trimSpaces(line.substr(0, comma))) == this->_rates.end())
			this->_rates[trimSpaces(line.substr(0, comma))] = trimSpaces(line.substr(comma + 1, line.length() - 1 - comma));
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &toCopy) {*this = toCopy;}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const &toAssign)
{
	if (this == &toAssign)
		return *this;
	this->_rates = std::map<std::string, std::string>(toAssign._rates);
	return *this;
}

void	BitcoinExchange::calculate(std::string const &input_file_name)
{
	std::ifstream	ifs(input_file_name.c_str(), std::ifstream::in);

	std::string	line;
	std::getline(ifs, line); // First line serves as header : "date | rate"

	size_t		sep = 0;
	std::string	date_str;
	std::string	rate_str;
	while (std::getline(ifs, line))
	{
		sep = line.find_first_of('|', 0);
		if (sep == line.npos) continue;

		date_str = trimSpaces(line.substr(0, sep));
		rate_str = trimSpaces(line.substr(sep + 1, line.length() - 1 - sep));

		// Input validation
		if (!isDateValid(date_str)) continue;

		size_t	rate = std::strtoul(rate_str.c_str(), NULL, 10);
		if (rate == 0 || rate > 100) continue;

		std::cout	<< "Debug: " << line << std::endl
					<< "  |- date: " << date_str << std::endl
					<< "  |- rate: " << rate_str << std::endl;
		std::cout	<< std::endl;
	}
}




/*	~~~~~~~~~~~~~~~~ UTILS ~~~~~~~~~~~~~~~~	*/


std::string	trimSpaces(std::string input)
{
	size_t	start = input.find_first_not_of(' ', 0);
	size_t	end = input.find_last_not_of(' ', input.npos);

	return (input.substr(start, end - start + 1));
}


bool	isDateValid(std::string date)
{
	size_t	first_sep = date.find_first_of('-', 0);
	size_t	last_sep = date.find_last_of('-', date.npos);

	std::string	year_str = date.substr(0, first_sep);
	std::string	month_str = date.substr(first_sep + 1, last_sep - first_sep - 1);
	std::string	day_str = date.substr(last_sep + 1, date.length() - last_sep - 1);

	if (year_str.length() > 4) return false;
	if (month_str.length() > 2) return false;
	if (day_str.length() > 2) return false;

	size_t year = std::strtoul(year_str.c_str(), NULL, 10);
	size_t month = std::strtoul(month_str.c_str(), NULL, 10);
	size_t day = std::strtoul(day_str.c_str(), NULL, 10);

	// Oldest possible date: 2009-01-02
	if (year < 2009) return false;
	if (year == 2009 && month == 1 && day == 1) return false;

	if (month == 0 || month > 12) return false;

	if (day > 31) return false;
	if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
	if (year % 4 != 0 && month == 2 && day > 28) return false;
	if (year % 4 == 0 && year % 100 == 0 && year % 400 != 0 && month == 2 && day > 28) return false;
	if (year % 4 == 0 && month == 2 && day > 29) return false;

	return true;
}
