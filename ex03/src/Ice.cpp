/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:57:38 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:48:30 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"
#include "../inc/ICharacter.hpp"

/**
 * Default constructor for Ice.
 *
 * This constructor creates a new Ice object with the default name "ice".
 * A message indicating the call to the default constructor is displayed.
 */
Ice::Ice(void) : AMateria("ice")
{
	//std::cout << GRN "✅ Ice Default constructor called" RESET << std::endl;
}

/**
 * Copy constructor for Ice.
 *
 * This constructor creates a new Ice object as a copy of an existing Ice object.
 * It initializes the new Ice with the same attributes as the provided Ice.
 * A message indicating the call to the copy constructor is displayed.
 *
 * @param rhs The Ice object to be copied.
 */
Ice::Ice(const Ice &rhs) : AMateria(rhs)
{
	//std::cout << GRN "✅ Ice Copy constructor called" RESET << std::endl;
	*this = rhs;
}

/**
 * @brief Destructor for the Ice class.
 *
 * Outputs a message indicating that the destructor has been called.
 */
Ice::~Ice(void)
{
	//std::cout << RED "❌ Ice Destructor called" RESET << std::endl;
}

/**
 * @brief Copy assignment operator for the Ice class.
 *
 * This operator allows one Ice object to be assigned the values of another Ice object.
 * It checks for self-assignment and then copies the type attribute from the provided Ice object.
 *
 * @param rhs The Ice object to be assigned.
 * @return A reference to the current object.
 */
Ice &Ice::operator=(const Ice &rhs)
{
	//std::cout << GRN "✅ Ice Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

/**
 * Creates a deep copy of the current Ice object.
 *
 * This function creates a new Ice object on the heap and initializes it
 * with the values of the current object. The new object is a deep copy,
 * meaning that any changes made to it will not affect the original object.
 *
 * @return A pointer to the newly created copy of the Ice object.
 */
AMateria *Ice::clone(void) const
{
	return (new Ice(*this));
}

/**
 * Outputs a message indicating that the Ice Materia has been used on the target.
 *
 * Outputs a message to the console indicating that the Ice Materia has been used
 * on the provided target character.
 *
 * @param target The target character on which to use the Ice Materia.
 */
void Ice::use(ICharacter &target)
{
	std::cout << YEL "🧊 * shoots an ice bolt at " << target.getName() << " *" RESET << std::endl;
}
