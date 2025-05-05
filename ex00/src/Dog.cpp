/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:01:50 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/05 15:08:27 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog(void) : Animal()
{
	type = "Dog";
	std::cout << GRN "✅ Dog Default constructor called" RESET << std::endl;
}

Dog::Dog(const Dog &rhs)
{
	std::cout << GRN "✅ Dog Copy constructor called" RESET << std::endl;
	*this = rhs;
}

Dog::~Dog(void)
{
	std::cout << RED "❌ Dog Destructor called" RESET << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << GRN "✅ Dog Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << YEL "🐶 Hau Hau..."  RESET << std::endl;
}
