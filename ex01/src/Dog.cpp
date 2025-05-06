/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:01:50 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:21:01 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

/**
 * Default constructor for Dog class.
 * Calls Animal default constructor.
 * Sets type to "Dog".
 * Instantiates a new Brain object.
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
 * This constructor creates a new Dog object as a copy of an existing one.
 * It initializes the base Animal class with the provided Dog object.
 * If the provided Dog has a Brain object, a deep copy of the Brain is made.
 * Otherwise, the Brain pointer is set to NULL.
 * It also copies the type attribute from the provided Dog object.
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
 * Outputs a message indicating that the destructor was called.
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
 * This operator checks for self-assignment and copies the type of the rhs object.
 * Prints a message when called.
 *
 * @param rhs The Dog object to copy from.
 * @return A reference to the modified Dog object.
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
 * @brief Returns the Brain object associated with the Dog.
 *
 * This function returns a pointer to the Brain object associated with the
 * Dog instance. If the Dog has no Brain (i.e., its Brain pointer is
 * NULL), a NULL pointer is returned.
 *
 * @return A pointer to the Brain object associated with the Dog, or NULL.
 */
Brain *Dog::getBrain(void) const
{
	return (this->brain);
}
