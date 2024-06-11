/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:36:01 by lgreau            #+#    #+#             */
/*   Updated: 2024/06/11 16:16:33 by lgreau           ###   ########.fr       */
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
			this->_rates[trimSpaces(line.substr(0, comma))] = trimSpaces(line.substr(comma + 1, line.length() - comma - 1));
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

void	BitcoinExchange::calculate(std::string const &input_file)
{
	(void)input_file;
}




/*	~~~~~~~~~~~~~~~~ UTILS ~~~~~~~~~~~~~~~~	*/


std::string	trimSpaces(std::string input)
{
	size_t	start = input.find_first_not_of(' ', 0);
	size_t	end = input.find_last_not_of(' ', input.npos);

	return (input.substr(start, end - start));
}


bool	isDateValid(std::string date)
{
	size_t	first_sep = date.find_first_of('-', 0);
	size_t	last_sep = date.find_last_of('-', date.npos);

	// Oldest possible date: 2009-01-02
	std::string	year = date.substr(0, first_sep);
	std::string	month = date.substr(first_sep + 1, last_sep - first_sep);
	std::string	day = date.substr(last_sep + 1, date.length() - last_sep - 1);

	std::cout	<< "Debug:" << std::endl
				<< "  |- year: " << year << std::endl
				<< "  |- month: " << month << std::endl
				<< "  |- day: " << day << std::endl;
	std::cout	<< std::endl;

	return true;
}
