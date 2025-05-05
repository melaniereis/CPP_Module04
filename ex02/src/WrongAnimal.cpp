/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:53:22 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/05 15:11:43 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << GRN "✅ WrongAnimal Default constructor called" RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
	std::cout << GRN "✅ WrongAnimal Copy constructor called" RESET << std::endl;
	*this = rhs;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED "❌ WrongAnimal Destructor called" RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << GRN "✅ WrongAnimal Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << CYN "WrongAnimal sound" RESET << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

std::ostream &operator<<(std::ostream &out, const WrongAnimal &rhs)
{
	out << rhs.getType();
	return (out);
}
