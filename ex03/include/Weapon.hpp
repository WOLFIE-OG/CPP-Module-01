/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:23:46 by otodd             #+#    #+#             */
/*   Updated: 2024/11/28 19:36:13 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H
# include <iostream>

class Weapon {
	private:
		std::string	type;
	public:
		Weapon(void);
		Weapon(std::string type);
		const std::string &getType(void);
		void				setType(std::string new_type);
};

#endif