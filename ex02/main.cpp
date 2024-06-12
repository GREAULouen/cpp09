/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:22:09 by lgreau            #+#    #+#             */
/*   Updated: 2024/06/12 17:06:32 by lgreau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <list>
#include <iomanip>
#include <sstream>
#include <ctime>

template<typename Container>
void	print(Container &a)
{
	for (typename Container::iterator	it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr	<< RED << "Error: The program requires at least 1 positive integer to perform the merge-insert sort on"
				<< RESET << std::endl;
		return 1;
	}

	{
		std::list<int>		l = std::list<int>();
		std::vector<int>	v = std::vector<int>();

		int	tmp;
		for (int i = 1; i < argc; ++i)
		{
			tmp = static_cast<int>(std::strtol(argv[i], NULL, 10));
			l.push_back(tmp);
			v.push_back(tmp);
		}

		std::cout << "Before : ";
		print<std::list<int> >(l);

		PmergeMe<std::list<int> >::mi_sort(l);
		PmergeMe<std::vector<int> >::mi_sort(v);

		std::cout << "After  : ";
		print<std::list<int> >(l);
	}

	return 0;
}
