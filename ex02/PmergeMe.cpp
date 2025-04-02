/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:10:04 by ademaill          #+#    #+#             */
/*   Updated: 2025/04/02 11:20:33 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		this->deque = src.deque;
		this->vector = src.vector;
		_lastElement = src._lastElement;
		_hasLast = src._hasLast;
	}
	return *this;
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe::PmergeMe(const std::vector <int> &input) : vector(input.begin(), input.end()), deque(input.begin(), input.end()), _lastElement(0), _hasLast(false) 
{}
void	PmergeMe::createPairs()
{
	if (vector.size() % 2 != 0)
	{
		_lastElement = vector.back();
		vector.pop_back();
		_hasLast = true;
	}
	
	for (size_t i = 0; i + 1 < vector.size(); i += 2)
	{
		if (vector[i] > vector[i + 1])
			std::swap(vector[i], vector[i + 1]);
		if (deque[i] > deque[i + 1])
			std::swap(deque[i], deque[i + 1]);
	}
}

void	PmergeMe::extractMins()
{
	std::vector<int> minVector;
	std::vector<int> maxVector;
	std::deque<int> minDeque;
	std::deque<int> maxDeque;

	for (size_t i = 0; i + 1 < vector.size(); i += 2)
	{
		minVector.push_back(vector[i]);
		maxVector.push_back(vector[i + 1]);
		minDeque.push_back(deque[i]);
		maxDeque.push_back(deque[i + 1]);
	}

	std::sort(minVector.begin(), minVector.end());
	std::sort(minDeque.begin(), minDeque.end());

	vector = std::move(minVector);
	deque = std::move(minDeque);

	vector.insert(vector.end(), maxVector.begin(), maxVector.end());
	deque.insert(deque.end(), maxDeque.begin(), maxDeque.end());

	if (_hasLast)
	{
		vector.push_back(_lastElement);
		deque.push_back(_lastElement);
	}
}

double	PmergeMe::measureSortTimeDeque()
{
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(deque.begin(), deque.end());
	auto end = std::chrono::high_resolution_clock::now();
	return std::chrono::duration<double, std::micro>(end - start).count();
}

double	PmergeMe::measureSortTimeVector()
{
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(vector.begin(), vector.end());
	auto end = std::chrono::high_resolution_clock::now();
	return std::chrono::duration<double, std::micro>(end - start).count();
}



void	PmergeMe::displayResults()
{
	std::cout << "After :";
	for (int num : vector)
		std::cout << num << " ";
	std::cout << std::endl;
	/*for (int num : deque)
		std::cout << num << " ";
	std::cout << std::endl;*/
}

void	PmergeMe::sort()
{
	std::cout << "Before: ";
    for (int num : vector) std::cout << num << " ";
    std::cout << std::endl;
	
	createPairs();
	extractMins();

	std::sort(vector.begin(), vector.end());
	std::sort(deque.begin(), deque.end());
	
	displayResults();

	double timeVector = measureSortTimeVector();
	double timeDeque = measureSortTimeDeque();
	
	
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << timeVector << " us\n";
    std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << timeDeque << " us\n";


}