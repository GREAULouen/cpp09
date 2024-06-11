/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:00:20 by lgreau            #+#    #+#             */
/*   Updated: 2024/06/11 16:16:47 by lgreau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "\033[0;31m" << "Error: program needs one and only one input file" << "\033[0m" << std::endl;
		return 1;
	}
	{
		BitcoinExchange exchanger = BitcoinExchange();
		exchanger.calculate(argv[1]);
	}
}
