/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:01:50 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:08:27 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

/**
 * Default constructor for Dog class.
 * Calls Animal default constructor.
 * Sets type to "Dog".
 * Prints a message when called.
 */
Dog::Dog(void) : Animal()
{
	type = "Dog";
	std::cout << GRN "✅ Dog Default constructor called" RESET << std::endl;
}

/**
 * Copy constructor for Dog class.
 * Calls Animal copy constructor.
 * Prints a message when called.
 * Copies the type of the rhs object.
 */
Dog::Dog(const Dog &rhs): Animal(rhs)
{
	std::cout << GRN "✅ Dog Copy constructor called" RESET << std::endl;
	*this = rhs;
}

/**
 * Destructor for Dog class.
 * Prints a message when called.
 */
Dog::~Dog(void)
{
	std::cout << RED "❌ Dog Destructor called" RESET << std::endl;
}

/**
 * Copy assignment operator for Dog class.
 * Checks for self-assignment.
 * Copies the type of the rhs object.
 * Prints a message when called.
 */
Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << GRN "✅ Dog Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/**
 * Outputs the sound associated with the Dog.
 *
 * This function prints the sound associated with a Dog ("Hau Hau...") to the console.
 */
void Dog::makeSound(void) const
{
	std::cout << YEL "🐶 Hau Hau..."  RESET << std::endl;
}
