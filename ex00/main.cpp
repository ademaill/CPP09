/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:14:24 by ademaill          #+#    #+#             */
/*   Updated: 2025/03/20 14:16:19 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error, usage : ./btc [file] " << std::endl;
		return 1;
	}
	BitcoinExchange exchange("data.csv");
	exchange.displayFromFile(argv[1]);
	return 0;
}