/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:59:49 by ademaill          #+#    #+#             */
/*   Updated: 2025/03/21 12:48:02 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
static bool	isValid(const std::string &str);
static bool	isOperator(char c);

RPN::RPN()
{}

RPN::RPN(const std::string &str)
{
	if (isValid(str))
		addStack(str);
}

RPN::~RPN()
{}

RPN	&RPN::operator=(RPN const &src)
{
	if (this != &src)
		this->_stack = src._stack;
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
		std::cout << "Error : not enough numbers" << std::endl;
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
				std::cout << "Error, division by zero" << std::endl;
				clearStack();
				return ;
			}
			_stack.push(operand1 / operand2);
			break;
	}
}

void	RPN::run() const
{
	if (this->_stack.size() == 1)
		std::cout << this->_stack.top() << std::endl;
	else
		std::cout << "Error, too many numbers" << std::endl;
}

void	RPN::clearStack()
{
	while (!this->_stack.empty())
		this->_stack.pop();
}

/*static bool	isOperator(char c)
{
	return (c == '/' || c == '*' || c == '+' || c == '-' );
}

static bool	isValid(const std::string &str)
{
	size_t len = str.length();
	
	if (len == 0 || str.find_first_not_of(' ') == std::string::npos)
	{
		std::cout << "Error : empty string" << std::endl;
		return false;
	}
	if (str.find_first_not_of("1234567890-+/* ") != std::string::npos)
	{
		std::cout << "Error : invalid character" << std::endl;
		return false;
	}

	size_t op_pos = str.find_first_of("+-/*");
	if (op_pos = std::string::npos || !isOperator(str[len - 1]))
	{
		std::cout << "Error : must contain at least one operator and end with an operator" << std::endl;
		return false;
	}
	if (len < 5 || len % 2 == 0)
	{
		std::cout << "Error : format must be \"x x x \"" << std::endl;
		return false;
	}
	for (size_t i = 0; i < len; i++)
	{
		if ((i % 2 == 0 && !isdigit(str[i]) && !isOperator(str[i])) ||
			(i % 2 == 1 && str[i] != ' '))
		{
			std::cout << "Error : format must be \"x x x\"" << std::endl;
			return false;
		}
	}
	return true;
}*/
static bool	isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

static bool	isValid(const std::string& str) {
	// Must not contain only spaces
	if (str.find_first_not_of(' ') == std::string::npos) {
		std::cout << "Error: empty string" << std::endl;
		return false;
	}

	// Must contain only digits, operators (+, -, *, /) and spaces
	if (str.find_first_not_of("0123456789+-*/ ") != std::string::npos) {
		std::cout << "Error: invalid character" << std::endl;
		return false;
	}

	// Must contain at least 1 operator
	if (str.find_first_of("+-*/") == std::string::npos) {
		std::cout << "Error: no operator" << std::endl;
		return false;
	}

	// Must be at least 3 characters long
	if (str.length() < 5) {
		std::cout << "Error: format must be \"x x x\"" << std::endl;
		return false;
	}

	// Last character must be an operator
	if (!isOperator(str[str.length() - 1])) {
		std::cout << "Error: last character must be an operator" << std::endl;
		return false;
	}

	// Must have correct format (x x x x x)
	for (size_t i = 0; i < str.length(); i++) {
		if (i % 2 == 0) {
			// if it's not a number or operator
			if (!isdigit(str[i]) && !isOperator(str[i])) {
				std::cout << "Error: format must be \"x x x\"" << std::endl;
				return false;
			}
		} else {
			// if it's not a space
			if (str[i] != ' ') {
				std::cout << "Error: format must be \"x x x\"" << std::endl;
				return false;
			}
		}
	}

	return true;
}
