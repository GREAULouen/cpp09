/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:22:09 by lgreau            #+#    #+#             */
/*   Updated: 2024/06/12 17:31:50 by lgreau           ###   ########.fr       */
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

		char	*end;
		int		tmp;
		for (int i = 1; i < argc; ++i)
		{
			tmp = static_cast<int>(std::strtol(argv[i], &end, 10));
			if (*end != '\0' || tmp < 0)
			{
				std::cerr	<< RED << "Error: invalid input: " << argv[i]
						<< RESET << std::endl;
				return 1;
			}
			l.push_back(tmp);
			v.push_back(tmp);
		}

		// Sequence pre-sort
		std::cout << "Before : ";
		print<std::list<int> >(l);

		clock_t	start_list = std::clock();
		PmergeMe<std::list<int> >::mi_sort(l);
		double	time_list = static_cast<double>(std::clock() - start_list) / CLOCKS_PER_SEC; // Convert the time it took for the list sorting to us


		clock_t	start_vector = std::clock();
		PmergeMe<std::vector<int> >::mi_sort(v);
		double	time_vector = static_cast<double>(std::clock() - start_vector) / CLOCKS_PER_SEC; // Convert the time it took for the vector sorting to us

		// Sequence post-sort
		std::cout << "After  : ";
		print<std::list<int> >(l);


		// List benchmark result output
		std::cout	<< "Time to process a range of "
					<< GREEN << std::setw(8) << (argc - 1) << RESET
					<< " elements with " << GREEN << "std::list<int>" << RESET << "   : "
					<< std::setw(12) << std::fixed << GREEN << time_list << RESET
					<< " us"
				<< std::endl;


		// Vector benchmark result output
		std::cout	<< "Time to process a range of "
					<< GREEN << std::setw(8) << (argc - 1) << RESET
					<< " elements with " << GREEN << "std::vector<int>" << RESET << " : "
					<< std::setw(12) << std::fixed << GREEN << time_vector << RESET
					<< " us"
				<< std::endl;
	}

	return 0;
}
