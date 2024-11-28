/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:52:40 by otodd             #+#    #+#             */
/*   Updated: 2024/11/28 17:58:26 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main()
{
	Zombie	*zombies = zombieHorde(10, "Rick");
	delete []zombies;
	return (0);
}