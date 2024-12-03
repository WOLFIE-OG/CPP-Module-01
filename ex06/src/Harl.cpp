/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:44:51 by otodd             #+#    #+#             */
/*   Updated: 2024/12/03 17:36:37 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl(void)
{
	this->DEBUG_MSGS[0] = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.";
	this->DEBUG_MSGS[1] = "I really do!";
	this->DEBUG_MSGS[2] = "I love the food here!";
	this->DEBUG_MSGS[3] = "I love the drinks here!";
	this->DEBUG_MSGS[4] = "All the staff are very friendly!";
	this->DEBUG_MSGS[5] = "I love this place.";
	this->INFO_MSGS[0] = "I cannot believe adding extra bacon costs more money.";
	this->INFO_MSGS[1] = "You didn’t put enough bacon in my burger!";
	this->INFO_MSGS[2] = "If you did, I wouldn’t be asking for more!";
	this->WARNING_MSGS[0] = "I think I deserve to have some extra bacon for free.";
	this->WARNING_MSGS[1] = "I’ve been coming for years whereas you started working here since last month.";
	this->ERROR_MSGS[0] = "This is unacceptable!";
	this->ERROR_MSGS[1] = "I want to speak to the manager now.";
}

void	Harl::printMsg(std::string a[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << a[i] << std::endl;
	std::cout << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "[ " << DEBUG_COLOUR << "DEBUG" << RESET_COLOUR << " ]" << std::endl;
	this->printMsg(this->DEBUG_MSGS, sizeof(this->DEBUG_MSGS) / sizeof(this->DEBUG_MSGS[0]));
}

void	Harl::info(void)
{
	std::cout << "[ " << INFO_COLOUR << "INFO" << RESET_COLOUR << " ]" << std::endl;
	this->printMsg(this->INFO_MSGS, sizeof(this->INFO_MSGS) / sizeof(this->INFO_MSGS[0]));
}


void	Harl::warning(void)
{
	std::cout << "[ " << WARNING_COLOUR << "WARNING" << RESET_COLOUR << " ]" << std::endl;
	this->printMsg(this->WARNING_MSGS, sizeof(this->WARNING_MSGS) / sizeof(this->WARNING_MSGS[0]));
}


void	Harl::error(void)
{
	std::cout << "[ " << ERROR_COLOUR << "ERROR" << RESET_COLOUR << " ]" << std::endl;
	this->printMsg(this->ERROR_MSGS, sizeof(this->ERROR_MSGS) / sizeof(this->ERROR_MSGS[0]));
}


void	Harl::complain(std::string level)
{	
	void	(Harl::*ptf[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int i;
	for (i = 0; i < 4; i++)
		if (level == levels[i])
			break;
	switch (i) {
		case 0:
			(this->*ptf[0])();
			(this->*ptf[1])();
			(this->*ptf[2])();
			(this->*ptf[3])();
			break;
		case 1:
			(this->*ptf[1])();
			(this->*ptf[2])();
			(this->*ptf[3])();
			break;
		case 2:
			(this->*ptf[2])();
			(this->*ptf[3])();
			break;
		case 3:
			(this->*ptf[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
	
}