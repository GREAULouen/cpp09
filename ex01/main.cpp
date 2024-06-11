/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:13:26 by lgreau            #+#    #+#             */
/*   Updated: 2024/06/11 21:50:10 by lgreau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr	<< "\033[0;31m" << "Error: the program takes one and only one Reverse Polish Notation string"
				<< "\033[0m" << std::endl;
		return 1;
	}
	RPN	rpn = RPN();
	rpn.compute(argv[1]);
	return 0;
}
