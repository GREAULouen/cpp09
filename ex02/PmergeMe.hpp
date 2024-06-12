/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:09:14 by lgreau            #+#    #+#             */
/*   Updated: 2024/06/12 14:57:48 by lgreau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

template<typename Container>
class PmergeMe
{
	private:
		Container	_small;
		Container	_large;


	public:
		PmergeMe() {}
		PmergeMe(PmergeMe const &toCopy) {*this = toCopy;}
		~PmergeMe() {}

		PmergeMe &	operator=(PmergeMe const &toAssign)
		{
			if (this == &toAssign) return *this;
			this->_small = toAssign._small;
			this->_large = toAssign._large;
			return *this;
		}


		void	mi_sort(Container &input)
		{
			if (input.size() < 1)
			{
				std::cerr	<< RED << "Error: the container is empty"
						<< RESET << std::endl;
				return ;
			}
		}

		/*	~~~~~~~~~~~~~~~~ UTILS ~~~~~~~~~~~~~~~~	*/

		void	split_n_sort_pairs(Container &input)
		{
			typename Container::iterator	it = input.begin();
			while (it != input.end())
			{
				typename Container::iterator first = it++;
				if (it != input.end()) {
					typename Container::iterator second = it++;
					if (*first < *second) {
						this->_small.push_back(*first);
						this->_large.push_back(*second);
					} else {
						this->_small.push_back(*second);
						this->_large.push_back(*first);
					}
				} else {
					this->_small.push_back(*first);
				}
			}
		}
};

#endif
