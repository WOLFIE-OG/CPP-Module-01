/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:44:54 by otodd             #+#    #+#             */
/*   Updated: 2024/12/03 17:15:59 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H
# include <iostream>
# define DEBUG_COLOUR "\033[94m"
# define INFO_COLOUR "\033[92m"
# define WARNING_COLOUR "\033[93m"
# define ERROR_COLOUR "\033[91m"
# define RESET_COLOUR "\033[0m"

class Harl {
	private:
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
		void		printMsg(std::string a[], int n);
		std::string	DEBUG_MSGS[6];
		std::string	INFO_MSGS[3];
		std::string	WARNING_MSGS[2];
		std::string	ERROR_MSGS[2];
	public:
		Harl(void);
		void		complain(std::string level);
};

#endif