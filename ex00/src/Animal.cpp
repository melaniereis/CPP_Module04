/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:10:26 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:07:15 by meferraz         ###   ########.fr       */
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
 * performs a deep copy of the object.
 */
Animal::Animal(const Animal &rhs)
{
	std::cout << GRN "✅ Animal Copy constructor called" RESET << std::endl;
	*this = rhs;
}

/**
 * @brief Destructor for the Animal class.
 *
 * Outputs a message indicating that the destructor has been called.
 */
Animal::~Animal(void)
{
	std::cout << RED "❌ Animal Destructor called" RESET << std::endl;
}

/**
 * @brief Copy assignment operator for the Animal class.
 *
 * Outputs a message indicating that the copy assignment operator has been called,
 * and performs a deep copy of the object.
 */
Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << GRN "✅ Animal Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/**
 * @brief Outputs the sound associated with the Animal.
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
 * Outputs the type of the animal to the provided output stream.
 *
 * @param out The output stream to write to.
 * @param rhs The Animal object to output.
 * @return The output stream after writing the animal type.
 */
std::ostream &operator<<(std::ostream &out, const Animal &rhs)
{
	out << rhs.getType();
	return (out);
}
