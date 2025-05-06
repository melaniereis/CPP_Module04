/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:49:45 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:40:30 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"
#include "../inc/ICharacter.hpp"

/**
 * AMateria Type constructor
 *
 * Constructs an AMateria object with type `type`.
 *
 * @param type The type of the AMateria.
 */
AMateria::AMateria(std::string const &type) : _type(type)
{
	//std::cout << GRN "✅ AMateria Type constructor called" RESET << std::endl;
}

/**
 * AMateria Default constructor
 *
 * Constructs an AMateria object with default type "unknown".
 */
AMateria::AMateria(void) : _type("unknown")
{
	//std::cout << GRN "✅ AMateria Default constructor called" RESET << std::endl;
}

/**
 * AMateria Copy constructor
 *
 * Constructs an AMateria object as a copy of `rhs`.
 *
 * @param rhs The AMateria object to copy.
 */
AMateria::AMateria(const AMateria &rhs)
{
	//std::cout << GRN "✅ AMateria Copy constructor called" RESET << std::endl;
	*this = rhs;
}

/**
 * AMateria Destructor
 *
 * Cleans up resources used by the AMateria object.
 */
AMateria::~AMateria(void)
{
	//std::cout << GRN "❌ AMateria Default destructor called" RESET << std::endl;
}

/**
 * AMateria Copy assignment operator
 *
 * Assigns the values of `rhs` to the current object.
 *
 * @param rhs The AMateria object to assign from.
 * @return A reference to the current object.
 */
AMateria &AMateria::operator=(const AMateria &rhs)
{
	//std::cout << GRN "✅ AMateria Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

/**
 * getType
 *
 * Returns the type of the AMateria.
 *
 * @return The type of the AMateria.
 */
std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

/**
 * use
 *
 * Outputs a message indicating that the AMateria has been used on the provided target.
 *
 * @param target The target character to use the AMateria on.
 */
void AMateria::use(ICharacter &target)
{
	std::cout << CYN "AMateria used on " << target.getName() << RESET << std::endl;
}

