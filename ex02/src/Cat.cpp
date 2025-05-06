/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:01:50 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:33:24 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

/**
 * Default constructor for Cat.
 *
 * This constructor will set the type of the Cat to "Cat".
 * It will also display a message indicating that the default constructor has been called.
 * A Brain object is also created and associated with the Cat.
 */
Cat::Cat(void) : Animal()
{
	std::cout << GRN "✅ Cat Default constructor called" RESET << std::endl;
	type = "Cat";
	brain = new Brain();
}

/**
 * Copy constructor for Cat.
 *
 * This constructor creates a new Cat object as a copy of an existing one.
 * It initializes the base Animal class with the provided Cat object.
 * If the provided Cat has a Brain object, a deep copy of the Brain is made.
 * Otherwise, the Brain pointer is set to NULL.
 * It also copies the type attribute from the provided Cat object.
 *
 * @param rhs The Cat object to copy from.
 */
Cat::Cat(const Cat &rhs) : Animal(rhs)
{
	std::cout << GRN "✅ Cat Copy constructor called" RESET << std::endl;
	if(rhs.brain)
		this->brain = new Brain(*rhs.brain);
	else
		this->brain = NULL;
	this->type = rhs.type;
}

/**
 * Destructor for Cat.
 *
 * This destructor is called when a Cat object is being destroyed.
 * It displays a message indicating that the destructor has been called.
 * It also deletes the Brain object associated with the Cat, if one exists.
 */
Cat::~Cat(void)
{
	std::cout << RED "❌ Cat Destructor called" RESET << std::endl;
	delete brain;
}

/**
 * Copy assignment operator for Cat.
 *
 * This operator allows one Cat object to be assigned the values of another Cat object.
 * It checks for self-assignment and then copies the attributes from the provided Cat.
 * A message indicating the call to the copy assignment operator is displayed.
 *
 * @param rhs The Cat object to be assigned.
 * @return A reference to the current object.
 */
Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << GRN "✅ Cat Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
	{
		if (this->brain)
			delete this->brain;
		if (rhs.brain)
			this->brain = new Brain(*rhs.getBrain());
		else
			this->brain = NULL;
		this->type = rhs.type;
	}
	return (*this);
}

/**
 * Outputs the sound associated with the Cat.
 *
 * This function prints a cat-specific sound, "Miauuuu...", to the console.
 */
void Cat::makeSound(void) const
{
	std::cout << MAG "🐱 Miauuuu..."  RESET << std::endl;
}

/**
 * @brief Returns the Brain object associated with the Cat.
 *
 * This function returns a pointer to the Brain object associated with the
 * Cat instance. If the Cat has no Brain (i.e., its Brain pointer is
 * NULL), a NULL pointer is returned.
 *
 * @return A pointer to the Brain object associated with the Cat, or NULL.
 */
Brain *Cat::getBrain(void) const
{
	return (this->brain);
}
