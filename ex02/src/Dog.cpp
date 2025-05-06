/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:01:50 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:34:15 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

/**
 * Default constructor for Dog class.
 * Initializes the base Animal class.
 * Sets type to "Dog".
 * Creates a new Brain object and assigns it to the brain pointer.
 * Prints a message when called.
 */
Dog::Dog(void) : Animal()
{
	std::cout << GRN "✅ Dog Default constructor called" RESET << std::endl;
	type = "Dog";
	brain = new Brain();
}

/**
 * Copy constructor for Dog class.
 *
 * Calls the Animal copy constructor.
 * Prints a message indicating that the copy constructor was called.
 * Copies the type and brain attributes of the provided Dog object.
 *
 * @param rhs The Dog object to copy from.
 */
Dog::Dog(const Dog &rhs) : Animal(rhs)
{
	std::cout << GRN "✅ Dog Copy constructor called" RESET << std::endl;
	if(rhs.brain)
		this->brain = new Brain(*rhs.brain);
	else
		this->brain = NULL;
	this->type = rhs.type;
}

/**
 * Destructor for Dog class.
 * Prints a message indicating that the destructor was called.
 * Deletes the brain pointer to free allocated memory.
 */
Dog::~Dog(void)
{
	std::cout << RED "❌ Dog Destructor called" RESET << std::endl;
	delete brain;
}

/**
 * Copy assignment operator for Dog class.
 *
 * Checks for self-assignment.
 * Copies the type and brain attributes of the provided Dog object.
 * Prints a message indicating that the copy assignment operator was called.
 *
 * @param rhs The Dog object to assign from.
 * @return A reference to the current object.
 */
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

/**
 * Outputs the sound associated with the Dog.
 *
 * This function prints the sound associated with a Dog ("Hau Hau...") to the console.
 */
void Dog::makeSound(void) const
{
	std::cout << YEL "🐶 Hau Hau..."  RESET << std::endl;
}

/**
 * @brief Retrieves the Brain object associated with the Dog.
 *
 * @return A pointer to the Brain object, or NULL if the Dog has no Brain.
 */
Brain *Dog::getBrain(void) const
{
	return (this->brain);
}
