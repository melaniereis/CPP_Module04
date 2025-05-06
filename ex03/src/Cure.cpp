/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:57:38 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:47:31 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"
#include "../inc/ICharacter.hpp"

Cure::Cure(void) : AMateria("cure")
{
	//std::cout << GRN "✅ Cure Default constructor called" RESET << std::endl;
}

/**
 * @brief Copy constructor for the Cure class.
 *
 * Creates a new Cure object as a copy of an existing one.
 *
 * @param rhs The Cure object to copy.
 */

Cure::Cure(const Cure &rhs) : AMateria(rhs)
{
	//std::cout << GRN "✅ Cure Copy constructor called" RESET << std::endl;
	*this = rhs;
}

/**
 * @brief Destructor for the Cure class.
 *
 * This function is the destructor for the Cure class. It is called when an instance
 * of the class is destroyed.
 */
Cure::~Cure(void)
{
	//std::cout << RED "❌ Cure Destructor called" RESET << std::endl;
}

/**
 * @brief Copy assignment operator for the Cure class.
 *
 * This operator allows one Cure object to be assigned the values of another Cure object.
 * It checks for self-assignment and then copies the type attribute from the provided Cure.
 * A message indicating the call to the copy assignment operator is displayed.
 *
 * @param rhs The Cure object to be assigned.
 * @return A reference to the current object.
 */
Cure &Cure::operator=(const Cure &rhs)
{
	//std::cout << GRN "✅ Cure Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

/**
 * @brief Creates a deep copy of the Cure object.
 *
 * This function is a pure virtual function in the AMateria class and must be implemented
 * by all derived classes. It creates a new instance of the Cure class and copies all the
 * attributes from the current object to the new object.
 *
 * @return A pointer to the newly created Cure object.
 */
AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}

/**
 * @brief Outputs a message indicating that the Cure has been used on the provided target.
 *
 * This function is a pure virtual function in the AMateria class and must be implemented
 * by all derived classes. It is called when the `use` function is called on an instance of
 * this class.
 *
 * @param target The target character on which to use the Cure.
 */
void Cure::use(ICharacter &target)
{
	std::cout << YEL "💊 * heals " << target.getName() << "'s wounds *" RESET << std::endl;
}
