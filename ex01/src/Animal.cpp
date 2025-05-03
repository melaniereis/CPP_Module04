/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 09:10:26 by meferraz          #+#    #+#             */
/*   Updated: 2025-05-03 09:10:26 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << GRN "✅ Animal Default constructor called" RESET << std::endl;
}

Animal::Animal(const Animal &rhs)
{
	std::cout << GRN "✅ Animal Copy constructor called" RESET << std::endl;
	*this = rhs;
}

Animal::~Animal(void)
{
	std::cout << RED "❌ Animal Destructor called" RESET << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << GRN "✅ Animal Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << CYN "Animal sound" RESET << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);
}

std::ostream &operator<<(std::ostream &out, const Animal &rhs)
{
	out << rhs.getType();
	return (out);
}
