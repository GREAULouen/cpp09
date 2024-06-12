/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:09:14 by lgreau            #+#    #+#             */
/*   Updated: 2024/06/12 16:01:41 by lgreau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

template<typename Container>
class PmergeMe
{
	private:
		PmergeMe() {}
		PmergeMe(PmergeMe const &toCopy) {*this = toCopy;}
		~PmergeMe() {}

		PmergeMe &	operator=(PmergeMe const &toAssign)
		{
			if (this == &toAssign) return *this;
			return *this;
		}


	public:
		static void	mi_sort(Container &input)
		{
			if (input.size() <= 1) return ;

			// Step 1: Separate elements by pairs & put the small/large in separated containers
			Container	small;
			Container	large;
			split_n_sort_pairs(input, small, large);

			// Step 2: Sort the container w/ the large values RECURSIVELY
			mi_sort(large);

			// Step 3: Insert the elements from small Container back at their place in the large Container
			//         Using a specific order
			std::vector<typename Container::iterator> insertionOrder = getInsertionOrder(small);
			for (size_t i = 0; i < insertionOrder.size(); ++i) {
				typename Container::iterator pos = std::lower_bound(large.begin(), large.end(), *insertionOrder[i]);
				large.insert(pos, *insertionOrder[i]);
			}

			// Step 4: Put the sorted values back into input Container
			input.swap(large);
		}

		/*	~~~~~~~~~~~~~~~~ UTILS ~~~~~~~~~~~~~~~~	*/

		/**
		 * @brief Separates the input container's elements in pairs & sorts them
		 * (if odd: leave one alone)
		 * @param input
		 */
		static void	split_n_sort_pairs(Container &input, Container &small, Container &large)
		{
			typename Container::iterator	it = input.begin();
			while (it != input.end())
			{
				typename Container::iterator	first = it++;
				if (it != input.end()) {
					typename Container::iterator	second = it++;
					if (*first < *second) {
						small.push_back(*first);
						large.push_back(*second);
					} else {
						small.push_back(*second);
						large.push_back(*first);
					}
				} else {
					small.push_back(*first);
				}
			}
		}

		/**
		 * @brief Generate the Jacobsthal Numbers sequence till n;
		 *
		 * @param n
		 * @return std::vector<int>
		 */
		static std::vector<int>	generateJacobsthalNumbers(int n) {
			std::vector<int> jacobsthal;
			jacobsthal.push_back(0); // J(1)
			jacobsthal.push_back(1); // J(2)
			for (int i = 2; ; ++i) {
				int next = jacobsthal[i-1] + 2 * jacobsthal[i-2];	// J[n + 2] = J[n + 1] + 2 * J[n]
				if (next >= n) break;
				jacobsthal.push_back(next);
			}
			return jacobsthal;
		}

		/**
		 * @brief Get the order of small Container elements insertion
		 *
		 * @param small
		 * @return std::vector<typename Container::iterator>
		 */
		static std::vector<typename Container::iterator> getInsertionOrder(Container& small) {
			std::vector<typename Container::iterator> order;
			int n = small.size();
			if (n == 0) return order;

			std::vector<int> jacobsthal = generateJacobsthalNumbers(n);
			std::vector<bool> inserted(n, false);

			for (size_t i = 1; i < jacobsthal.size(); ++i) {
				int idx = jacobsthal[i] - 1;
				if (idx < n && !inserted[idx]) {
					typename Container::iterator it = small.begin();
					std::advance(it, idx);
					order.push_back(it);
					inserted[idx] = true;
				}
			}

			for (int i = 0; i < n; ++i) {
				if (!inserted[i]) {
					typename Container::iterator it = small.begin();
					std::advance(it, i);
					order.push_back(it);
				}
			}

			return order;
		}
};

#endif
