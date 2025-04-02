/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:59:49 by ademaill          #+#    #+#             */
/*   Updated: 2025/04/02 11:06:03 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
static bool	isValid(const std::string &str);
static bool	isOperator(char c);

RPN::RPN()
{}

RPN::RPN(const std::string &str) : _error_div(false)
{
	if (isValid(str))
		addStack(str);
}

RPN::~RPN()
{}

RPN	&RPN::operator=(RPN const &src)
{
	if (this != &src)
	{
		_error_div = src._error_div;
		this->_stack = src._stack;
	}
	return *this;
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

void	RPN::addStack(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			continue;
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			calculate(str[i]);
		else
			this->_stack.push(std::atoi(str.substr(i).c_str()));
	}
}

void	RPN::calculate(char op)
{
	if (this->_stack.size() < 2)
	{
		if (!_error_div)
			std::cerr << "Error : not enough numbers" << std::endl;
		clearStack();
		return;
	}
	int	operand2 = _stack.top();
	_stack.pop();
	int	operand1 = _stack.top();
	_stack.pop();

	switch (op)
	{
		case '+' :
			_stack.push(operand1 + operand2);
			break;
		case '-' :
			_stack.push(operand1 - operand2);
			break;
		case '*' :
			_stack.push(operand1 * operand2);
			break;
		case '/' :
			if (operand2 == 0)
			{
				std::cerr << "Error : division by zero" << std::endl;
				this->_error_div = true;
				clearStack();
				return;
			}
			_stack.push(operand1 / operand2);
			break;
	}
}

void	RPN::display() const
{
	if (this->_stack.size() == 1)
		std::cout << this->_stack.top() << std::endl;
	if (this->_stack.size() > 1)
		std::cerr << "Error, too many numbers" << std::endl;
}

void	RPN::clearStack()
{
	while (!this->_stack.empty())
		this->_stack.pop();
}

static bool	isOperator(char c)
{
	return (c == '/' || c == '*' || c == '+' || c == '-' );
}

static bool	isValid(const std::string &str)
{
	size_t len = str.length();
	
	if (len == 0 || str.find_first_not_of(' ') == std::string::npos)
	{
		std::cerr << "Error : empty string" << std::endl;
		return false;
	}
	if (str.find_first_not_of("1234567890-+/* ") != std::string::npos)
	{
		std::cerr << "Error : invalid character" << std::endl;
		return false;
	}

	size_t op_pos = str.find_first_of("+-/*");
	if (op_pos == std::string::npos || !isOperator(str[len - 1]))
	{
		std::cerr << "Error : must contain at least one operator and end with an operator" << std::endl;
		return false;
	}
	if (len < 5 || len % 2 == 0)
	{
		std::cerr << "Error : format must be \"x x x\"" << std::endl;
		return false;
	}
	for (size_t i = 0; i < len; i++)
	{
		if ((i % 2 == 0 && !isdigit(str[i]) && !isOperator(str[i])) ||
			(i % 2 == 1 && str[i] != ' '))
		{
			std::cerr << "Error : format must be \"x x x\"" << std::endl;
			return false;
		}
	}
	return true;
}