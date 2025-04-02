/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:52:28 by ademaill          #+#    #+#             */
/*   Updated: 2025/04/02 11:11:04 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <chrono>


class	PmergeMe
{
	public :
		PmergeMe(const std::vector<int> &input);
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		void	sort();
		~PmergeMe();
		
	private :
		std::vector<int> vector;
		std::deque<int> deque;
		int				_lastElement;
		bool			_hasLast;

		void	createPairs();
		void	extractMins();
		void	displayResults();
		double	measureSortTimeVector();
		double	measureSortTimeDeque();

		PmergeMe();

};

#endif