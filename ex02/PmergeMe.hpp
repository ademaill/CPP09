#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <ctime>
#include <iomanip>

class PmergeMe 
{
	public :
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		bool isValidNumber(const std::string& str);
		void Inputs(int argc, char* argv[]);
		void createPairs();
		void extractMins();
		void insertMaxs();
		void sortAndInsertMaxs();
		void removeMinusOne();
		void displayContainers() const;
		void displayFinalResults() const;
		void displayExecutionTime() const;
		void startVectorTimer();
        void stopVectorTimer();
        void startDequeTimer();
        void stopDequeTimer();
		void sortFinalVector();

	private :
		std::vector<int> vector;
		std::deque<int> deque;
		std::vector<std::pair<int, int> > even;
		std::vector<int> final_vector;
		std::deque<int> final_deque;
		double time_vector;
		double time_deque;
		clock_t start_vector;
		clock_t end_vector;
		clock_t start_deque;
		clock_t end_deque;
};


#endif