/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:38:58 by lgreau            #+#    #+#             */
/*   Updated: 2024/06/11 21:33:44 by lgreau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>

class RPN
{
	private:
		std::stack<int>	_tokens;

	public:
		RPN();
		RPN(RPN const &);
		~RPN();

		RPN &	operator=(RPN const &);

		void	compute(std::string input);
};

int		which_of(std::string input, std::string *arr, int arr_size);
int		rpn_add(int a, int b);
int		rpn_sub(int a, int b);
int		rpn_div(int a, int b);
int		rpn_mult(int a, int b);

#endif
