/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:44:56 by lgreau            #+#    #+#             */
/*   Updated: 2024/06/11 21:11:36 by lgreau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(RPN const &toCopy) {*this = toCopy;}
RPN::~RPN() {}

RPN &	RPN::operator=(RPN const &toAssign)
{
	if (this == &toAssign)
		return *this;
	this->_tokens = toAssign._tokens;
	return *this;
}

void	RPN::compute(std::string input)
{
	std::cout << "input: " << input << std::endl;
	std::ostringstream	oss(input, std::ostringstream::in);
	std::string	operators[4] = {"+", "-", "/", "*"};

	size_t	next_op = input.npos;
	while (true)
	{
		next_op = which_of(input, operators, 4);
		if (next_op == -1)
		{
			// Numeric value
			std::cout << "  |- next_val : " << oss.str();
			// Convert to int then stack up
		} else {
			std::cout << "  |- next_op  : " << operators[next_op] << std::endl;
			// Verify that there's at least 2 operands in the stack
			// Retrieve the first 2 operands from the stack
			// Execute the operation on them
			// Stack up the result form the operation
		}

	}
}


/*	~~~~~~~~~~~~~~~~ UTILS ~~~~~~~~~~~~~~~~	*/


int	which_of(std::string input, std::string *arr, int arr_size)
{
	std::string	ref = input.substr(0, 1);
	for (int i = 0; i < arr_size; ++i)
		if (ref.compare(arr[i]) == 0)
			return i;
	return -1;
}
