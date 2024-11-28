/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:52:40 by otodd             #+#    #+#             */
/*   Updated: 2024/11/28 17:33:03 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie	*newZombie(std::string name);
void 	randomChump(std::string name);

int	main()
{
	Zombie	*z = newZombie("Rick");
	Zombie	*z1 = newZombie("Dale");
	Zombie	*z2 = newZombie("Glen");
	Zombie	*z3 = newZombie("Darel");
	Zombie	*z4 = newZombie("Carl");
	delete z;
	delete z1;
	delete z2;
	delete z3;
	delete z4;
	randomChump("Negan");
	randomChump("Govner");
	return (0);
}