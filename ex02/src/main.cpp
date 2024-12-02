/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:52:40 by otodd             #+#    #+#             */
/*   Updated: 2024/11/28 18:12:57 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;
	std::cout << "Original: " << &str << std::endl;
	std::cout << "Pointer: " << stringPTR << std::endl;
	std::cout << "Reference: " << &stringREF << std::endl;
	std::cout << std::endl << "Original: " << str << std::endl;
	std::cout << "Pointer: " << *stringPTR << std::endl;
	std::cout << "Reference: " << stringREF << std::endl;
	return (0);
}