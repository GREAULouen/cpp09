/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:22:09 by lgreau            #+#    #+#             */
/*   Updated: 2024/06/12 14:58:09 by lgreau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <list>
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(time(NULL));
	{
		std::list<int> list(10);
		std::generate(list.begin(), list.end(), std::rand);

		PmergeMe<std::list<int> > pmerge_me = PmergeMe<std::list<int> >();

		pmerge_me.mi_sort(list);
	}
	return 0;
}
