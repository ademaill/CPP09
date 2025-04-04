/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:41:26 by ademaill          #+#    #+#             */
/*   Updated: 2025/03/26 11:38:30 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage : ./rpn \"expression\"" << std::endl;
		return 0;
	}
	RPN rpn(argv[1]);
	rpn.display();
	return 0;
}