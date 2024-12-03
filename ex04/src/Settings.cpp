/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Settings.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otodd <otodd@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:59:08 by otodd             #+#    #+#             */
/*   Updated: 2024/12/03 18:17:12 by otodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Settings.hpp"

Settings::Settings(std::string filename, std::string s1, std::string s2)
{
	this->s1 = s1;
	this->s2 = s2;
	this->filename = filename;
	this->in_file.open(this->filename.c_str());
	if (!this->in_file.is_open())
		std::cerr << "Failed to open file!";
}

Settings::~Settings(void)
{
	if (this->in_file.is_open())
		this->in_file.close();
	if (this->out_file.is_open())
		this->out_file.close();
}

void	Settings::write(void)
{
	if (!this->in_file.is_open())
		return ;
	this->out_file.open(this->filename.append(".replace").c_str());
	if (this->out_file.is_open())
		this->out_file.write(this->buffer.c_str(), this->buffer.length());
}

void	Settings::read(void)
{
	std::string	line;
	while (getline(this->in_file, line))
	{
		if (this->in_file.peek() == '\n')
			line.push_back('\n');
		if (line.empty())
			this->buffer.append("\n");
		this->buffer.append(line);
	}
}

void	Settings::replace(void)
{
	if (!this->in_file.is_open())
		return ;

	std::string	result;
	size_t		start = 0;
	size_t		i = 0;

	while (i < this->buffer.length())
	{
		start = this->buffer.find(this->s1, i);
		if (start == std::string::npos)
		{
			result.append(this->buffer.substr(i));
			break;
		}
		result.append(this->buffer.substr(i, (start - i)));
		result.append(this->s2);
		i = start + this->s1.length();
	}
	this->buffer = result;
}

