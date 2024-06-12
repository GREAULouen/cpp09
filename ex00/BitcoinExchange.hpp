/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:24:56 by lgreau            #+#    #+#             */
/*   Updated: 2024/06/12 12:25:14 by lgreau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <exception>
# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <cstdlib>

class BitcoinExchange
{
	private:
		std::map< std::string, std::string>	_rates;

		std::string	_find_closest_date(std::string);

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &);
		~BitcoinExchange();

		BitcoinExchange &	operator=(BitcoinExchange const &);

		void	calculate(std::string const &input_file_name);
};

std::string	trimSpaces(std::string);
bool		isDateValid(std::string);
std::string	dateToString(size_t year, size_t month, size_t day);
double		getFinalAmount(std::string rate_str, double amount);

#endif
