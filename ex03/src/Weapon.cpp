/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:24:13 by otodd             #+#    #+#             */
/*   Updated: 2024/11/28 19:42:45 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(void)
{
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

const std::string &Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string new_type)
{
	this->type = new_type;
}