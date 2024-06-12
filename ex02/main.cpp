/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:22:09 by lgreau            #+#    #+#             */
/*   Updated: 2024/06/12 16:02:35 by lgreau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <list>
#include <cstdlib>
#include <ctime>

template<typename Container>
void	print(Container &a)
{
	for (typename Container::iterator	it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;
}

int main(void)
{
	std::srand(time(NULL));
	{
		std::list<int> list(500);
		std::generate(list.begin(), list.end(), std::rand);

		std::cout	<< "Before : " << ((std::is_sorted(list.begin(), list.end()))?GREEN:RED);
		print<std::list<int> >(list);
		std::cout	<< RESET;

		PmergeMe<std::list<int> >::mi_sort(list);

		std::cout	<< "After  : " << ((std::is_sorted(list.begin(), list.end()))?GREEN:RED);
		print<std::list<int> >(list);
		std::cout	<< RESET;

		std::cout << "Debug: " << list.size() << " elements after mi_sort" << std::endl;
	}
	return 0;
}
