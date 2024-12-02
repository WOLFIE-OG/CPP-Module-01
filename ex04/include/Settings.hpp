/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Settings.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:59:24 by otodd             #+#    #+#             */
/*   Updated: 2024/12/02 16:03:53 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H
# include <iostream>
# include <fstream>

class Settings {
	private:
		std::string		buffer;
		std::ifstream	in_file;
		std::ofstream	out_file;
	public:
		Settings(std::string filename, std::string s1, std::string s2);
		~Settings(void);
		void	write(void);
		void	read(void);
		void	replace(void);
		std::string		filename;
		std::string		s1;
		std::string		s2;
};

#endif