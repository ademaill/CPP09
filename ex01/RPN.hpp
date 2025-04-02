/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:52:55 by ademaill          #+#    #+#             */
/*   Updated: 2025/04/02 11:03:47 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPM_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN
{
	private:
		RPN();
		std::stack<int>	_stack;
		bool			_error_div;

		void	addStack(const std::string &str);
		void	calculate(char op);
		void	clearStack();

	public:
	
		RPN(const std::string &str);
		RPN(const RPN &src);
		RPN	&operator=(const RPN &src);
		~RPN();
		void	display() const;

};



#endif