/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:57:58 by otodd             #+#    #+#             */
/*   Updated: 2024/12/02 16:11:22 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Settings.hpp"

int	main(int argc, char **argv)
{
	if (argc < 4)
	{
		std::cerr << "Too few args to run program!";
		return (1);
	}
	Settings	s(argv[1], argv[2], argv[3]);
	s.read();
	s.replace();
	s.write();
	return (0);
}