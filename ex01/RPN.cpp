/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:44:56 by lgreau            #+#    #+#             */
/*   Updated: 2024/06/11 21:47:27 by lgreau           ###   ########.fr       */
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
	std::stringstream	ss(input, std::stringstream::in);
	std::string	operators[4] = {"+", "-", "/", "*"};
	int (*operations[4])(int, int) = {&rpn_add, &rpn_sub, &rpn_div, &rpn_mult};

	int	next_op;
	int	value;
	int	op_a;
	int	op_b;
	while (ss >> input) // Using the ss to "move" the input char by char
	{
		next_op = which_of(input, operators, 4);
		if (next_op == -1)
		{
			// Convert to int then stack up
			value = static_cast<int>(std::strtol(input.substr(0, 1).c_str(), NULL, 10));
			std::cout << "  |- value    : " << value << std::endl;
			this->_tokens.push(value);
		} else {
			std::cout << "  |- next_op  : " << operators[next_op] << std::endl;

			// Verify that there's at least 2 operands in the stack
			if (this->_tokens.size() < 2)
			{
				std::cerr << "Error: " << operators[next_op] << " execution impossible: Not enough operands" << std::endl;
				return ;
			}

			// Retrieve the first 2 operands from the stack
			op_b = this->_tokens.top();
			this->_tokens.pop();
			op_a = this->_tokens.top();
			this->_tokens.pop();

			// Execute the operation on them
			// Stack up the result form the operation
			this->_tokens.push(operations[next_op](op_a, op_b));
		}
	}

	// Verify that there's no leftover operands
	if (this->_tokens.size() > 1)
	{
		std::cerr << "Error: " << this->_tokens.size() << " too much operands" << std::endl;
		return ;
	}

	std::cout << " => " << this->_tokens.top() << std::endl;
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

int	rpn_add(int a, int b)
{
	return a + b;
}

int	rpn_sub(int a, int b)
{
	return a - b;
}

int	rpn_div(int a, int b)
{
	return a / b;
}

int	rpn_mult(int a, int b)
{
	return a * b;
}

