/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:27:17 by otodd             #+#    #+#             */
/*   Updated: 2024/11/28 17:57:40 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie()
{
	this->index = 0;
}

Zombie::~Zombie(void)
{
	std::cout << this->index << " | " << this << " | " << this->name << " gave in to the virus [Destroyed]" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->index << " | " << this << " | " << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::init(std::string name, int i)
{
	this->index = i;
	this->name = name;
	this->announce();
}