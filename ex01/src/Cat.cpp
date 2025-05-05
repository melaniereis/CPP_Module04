/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:01:50 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/05 15:11:22 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << GRN "✅ Cat Default constructor called" RESET << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &rhs) : Animal(rhs)
{
	std::cout << GRN "✅ Cat Copy constructor called" RESET << std::endl;
	if(rhs.brain)
		this->brain = new Brain(*rhs.brain);
	else
		this->brain = NULL;
	this->type = rhs.type;
}

Cat::~Cat(void)
{
	std::cout << RED "❌ Cat Destructor called" RESET << std::endl;
	delete brain;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << GRN "✅ Cat Copy assignment operator called" RESET << std::endl;
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

void Cat::makeSound(void) const
{
	std::cout << MAG "🐱 Miauuuu..."  RESET << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (this->brain);
}
