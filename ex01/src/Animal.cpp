/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:10:26 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:17:36 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

/**
 * @brief Default constructor for the Animal class.
 *
 * Initializes the type of the animal to "Animal" and outputs a message indicating
 * that the default constructor has been called.
 */
Animal::Animal(void) : type("Animal")
{
	std::cout << GRN "✅ Animal Default constructor called" RESET << std::endl;
}

/**
 * @brief Copy constructor for the Animal class.
 *
 * Outputs a message indicating that the copy constructor has been called, and
 * performs a deep copy of the object by calling the copy assignment operator.
 *
 * @param rhs The Animal object to copy from.
 */
Animal::Animal(const Animal &rhs)
{
	std::cout << GRN "✅ Animal Copy constructor called" RESET << std::endl;
	*this = rhs;
}

/**
 * @brief Destructor for the Animal class.
 *
 * Outputs a message indicating that the destructor has been called, and releases any
 * resources allocated by the object.
 */
Animal::~Animal(void)
{
	std::cout << RED "❌ Animal Destructor called" RESET << std::endl;
}

/**
 * @brief Copy assignment operator for the Animal class.
 *
 * Outputs a message indicating that the copy assignment operator has been called,
 * and performs a deep copy of the object by copying the type attribute.
 *
 * @param rhs The Animal object to assign from.
 * @return A reference to the current object.
 */
Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << GRN "✅ Animal Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/**
 * Outputs the sound associated with the Animal.
 *
 * This function prints a generic animal sound to the console.
 */
void Animal::makeSound(void) const
{
	std::cout << CYN "Animal sound" RESET << std::endl;
}

/**
 * @brief Retrieves the type of the animal.
 *
 * @return The type of the animal, as a std::string.
 */
std::string Animal::getType(void) const
{
	return (this->type);
}

/**
 * @brief Overloaded output operator for the Animal class.
 *
 * This operator allows the Animal object to be output to a stream.
 *
 * @param out The output stream.
 * @param rhs The Animal object to output.
 * @return The output stream.
 */
std::ostream &operator<<(std::ostream &out, const Animal &rhs)
{
	out << rhs.getType();
	return (out);
}
