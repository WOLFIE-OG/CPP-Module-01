/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:23:40 by otodd             #+#    #+#             */
/*   Updated: 2024/11/28 20:05:52 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H
# include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name);
		Weapon		*weapon;
		std::string	name;
		void		attack(void);
		void		setWeapon(Weapon &weapon);
};

#endif