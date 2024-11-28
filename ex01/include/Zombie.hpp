/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:52:37 by otodd             #+#    #+#             */
/*   Updated: 2024/11/28 17:55:05 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>

class Zombie {
	private:
		std::string	name;
		void		announce(void);
	public:
		int			index;
		void		init(std::string name, int i);
		Zombie(void);
		~Zombie(void);
};

#endif