#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : time_vector(0), time_deque(0), start_vector(0), start_deque(0), end_deque(0) 
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
    :   vector(other.vector), deque(other.deque), even(other.even),
        final_vector(other.final_vector), final_deque(other.final_deque),
        time_vector(other.time_vector), time_deque(other.time_deque),
        start_vector(other.start_vector), end_vector(other.end_vector),
        end_deque(other.end_deque), end_vector(other.end_vector)
{
}

PmergeMe    &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other) {
        vector = other.vector;
        deque = other.deque;
        even = other.even;
        final_vector = other.final_vector;
        final_deque = other.final_deque;
        time_vector = other.time_vector;
        time_deque = other.time_deque;
        start_vector = other.start_vector;
        end_vector = other.end_vector;
        start_deque = other.start_deque;
        end_deque = other.end_deque;
    }
    return *this;
}

bool    PmergeMe::isValidNumber(const std::string &str)
{
    if (str.empty())
        throw std::runtime_error("Error : Empty string is not a valid number.");
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (!isdigit(str[i]))
            throw std::runtime_error("Error");
    }
    return true;
}

void PmergeMe::Inputs(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (isValidNumber(arg))
        {
            vector.push_back(std::atoi(arg.c_str()));
            deque.push_back(std::atoi(arg.c_str()));
        }
    }
}