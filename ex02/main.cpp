/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:25:31 by ademaill          #+#    #+#             */
/*   Updated: 2025/04/02 11:15:44 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage : " << argv[0] << " <list of numbers>" << std::endl;
		return 1;
	}
	
	std::vector<int> input;
	for (int i = 1; i < argc; ++i)
	{
		int convert = std::atoi(argv[i]);
		if (convert >= 0)
			input.push_back(convert);
		else
		{
			std::cerr << "Numbers must be positif" << std::endl;
			return 1;
		}
	}
	PmergeMe sorter(input);
	sorter.sort();
	return 0;
}