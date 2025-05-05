/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:01:50 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/05 14:58:57 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << GRN "✅ Dog Default constructor called" RESET << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &rhs) : Animal(rhs)
{
	std::cout << GRN "✅ Dog Copy constructor called" RESET << std::endl;
	if(rhs.brain)
		this->brain = new Brain(*rhs.brain);
	else
		this->brain = NULL;
	this->type = rhs.type;
}

Dog::~Dog(void)
{
	std::cout << RED "❌ Dog Destructor called" RESET << std::endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << GRN "✅ Dog Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
	{
		if (this->brain)
			delete this->brain;
		if (rhs.brain)
			this->brain = new Brain(*rhs.brain);
		else
			this->brain = NULL;
		this->type = rhs.type;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << YEL "🐶 Hau Hau..."  RESET << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return (this->brain);
}
