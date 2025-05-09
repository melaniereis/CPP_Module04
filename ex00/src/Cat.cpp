/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:01:50 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:07:47 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

/**
 * Default constructor for Cat.
 *
 * This constructor will set the type of the Cat to "Cat".
 * It will also display a message indicating that the default constructor has been called.
 */
Cat::Cat(void) : Animal()
{
	std::cout << GRN "✅ Cat Default constructor called" RESET << std::endl;
	type = "Cat";
}

/**
 * Copy constructor for Cat.
 *
 * This constructor creates a new Cat object as a copy of an existing Cat object.
 * It initializes the new Cat with the same attributes as the provided Cat.
 * A message indicating the call to the copy constructor is displayed.
 *
 * @param rhs The Cat object to be copied.
 */
Cat::Cat(const Cat &rhs) : Animal(rhs)
{
	std::cout << GRN "✅ Cat Copy constructor called" RESET << std::endl;
	*this = rhs;
}

/**
 * Destructor for Cat.
 *
 * This destructor is called when a Cat object is being destroyed.
 * It displays a message indicating that the destructor has been called.
 */
Cat::~Cat(void)
{
	std::cout << RED "❌ Cat Destructor called" RESET << std::endl;
}

/**
 * Copy assignment operator for Cat.
 *
 * This operator allows one Cat object to be assigned the values of another Cat object.
 * It checks for self-assignment and then copies the attributes from the provided Cat.
 * A message indicating the call to the copy assignment operator is displayed.
 *
 * @param rhs The Cat object to be assigned.
 * @return A reference to the current Cat object.
 */
Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << GRN "✅ Cat Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/**
 * @brief Outputs the sound associated with the Cat.
 *
 * This function prints a cat-specific sound, "Miauuuu...", to the console.
 */

void Cat::makeSound(void) const
{
	std::cout << MAG "🐱 Miauuuu..."  RESET << std::endl;
}
