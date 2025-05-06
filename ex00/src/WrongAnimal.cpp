/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:53:22 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:14:35 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

/**
 * Default constructor for WrongAnimal.
 * Sets the type to "WrongAnimal".
 * Logs a message to indicate that the default constructor was called.
 */
WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << GRN "✅ WrongAnimal Default constructor called" RESET << std::endl;
}

/**
 * @brief Copy constructor for the WrongAnimal class.
 *
 * This constructor creates a new WrongAnimal object as a copy of an existing one.
 * It outputs a message indicating that the copy constructor has been called.
 * The assignment operator is used to copy the properties of the existing object.
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
 * @brief Copy assignment operator for the WrongAnimal class.
 *
 * This operator allows one WrongAnimal object to be assigned the values of another.
 * It checks for self-assignment and then copies the properties from the provided object.
 * A message indicating the call to the copy assignment operator is displayed.
 *
 * @param rhs The WrongAnimal object to be assigned.
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
 * @return The type of the WrongAnimal, as a std::string.
 */
std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

/**
 * @brief Overloaded output operator for the WrongAnimal class.
 *
 * Outputs the type of the WrongAnimal to the provided output stream.
 *
 * @param out The output stream to write to.
 * @param rhs The WrongAnimal object to output.
 * @return The output stream after writing the type.
 */
std::ostream &operator<<(std::ostream &out, const WrongAnimal &rhs)
{
	out << rhs.getType();
	return (out);
}
