/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademaill <ademaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:16:08 by ademaill          #+#    #+#             */
/*   Updated: 2025/04/02 11:16:11 by ademaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

class BitcoinExchange
{
	public :
		BitcoinExchange(const std::string &database_file);
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange	&operator=(BitcoinExchange const &src);

		void	showDatabase() const;
		void	displayFromFile(const std::string &filename) const;
	private :

		float	getExchangeRate(const std::string &date) const;
		BitcoinExchange();
		std::map<std::string, float> _dataBase;
};

#endif