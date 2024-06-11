/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:24:56 by lgreau            #+#    #+#             */
/*   Updated: 2024/06/11 16:42:28 by lgreau           ###   ########.fr       */
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

class BitcoinExchange
{
	private:
		std::map< std::string, std::string>	_rates;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &);
		~BitcoinExchange();

		BitcoinExchange &	operator=(BitcoinExchange const &);

		void	calculate(std::string const &input_file_name);
};

std::string	trimSpaces(std::string);
bool		isDateValid(std::string);

#endif
