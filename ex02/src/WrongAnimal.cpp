/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:53:22 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:37:14 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

/**
 * Default constructor for WrongAnimal.
 *
 * Sets the type to "WrongAnimal".
 * Logs a message to indicate that the default constructor was called.
 */
WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << GRN "✅ WrongAnimal Default constructor called" RESET << std::endl;
}

/**
 * Copy constructor for WrongAnimal.
 *
 * Outputs a message indicating that the copy constructor has been called, and
 * performs a deep copy of the object by calling the copy assignment operator.
 *
 * @param rhs The WrongAnimal object to copy from.
 */
WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
	std::cout << GRN "✅ WrongAnimal Copy constructor called" RESET << std::endl;
	*this = rhs;
}

/**
 * @brief Destructor for the WrongAnimal class.
 *
 * Outputs a message indicating that the destructor has been called.
 */
WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED "❌ WrongAnimal Destructor called" RESET << std::endl;
}

/**
 * Copy assignment operator for WrongAnimal.
 *
 * Outputs a message indicating that the copy assignment operator has been called,
 * and performs a deep copy of the object by copying the type attribute.
 *
 * @param rhs The WrongAnimal object to assign from.
 * @return A reference to the current object.
 */
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << GRN "✅ WrongAnimal Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/**
 * Outputs the sound associated with the WrongAnimal.
 *
 * This function prints a generic WrongAnimal sound to the console.
 */
void WrongAnimal::makeSound(void) const
{
	std::cout << CYN "WrongAnimal sound" RESET << std::endl;
}

/**
 * @brief Retrieves the type of the WrongAnimal.
 *
 * This function returns the type of the WrongAnimal as a string.
 *
 * @return The type of the WrongAnimal, as a std::string.
 */
std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

/**
 * @brief Outputs the type of the WrongAnimal to the provided output stream.
 *
 * This function overloads the << operator to allow for easy printing of
 * the WrongAnimal's type.
 *
 * @param out The output stream to write to.
 * @param rhs The WrongAnimal object to print.
 * @return The output stream after writing the type.
 */
std::ostream &operator<<(std::ostream &out, const WrongAnimal &rhs)
{
	out << rhs.getType();
	return (out);
}
