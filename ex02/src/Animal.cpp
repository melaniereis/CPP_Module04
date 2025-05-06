/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:10:26 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:25:48 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

/**
 * @brief Default constructor for Animal.
 * Initializes the type of the animal to "Animal" and outputs a message indicating
 * that the default constructor has been called.
 */
Animal::Animal(void) : type("Animal")
{
	std::cout << GRN "✅ Animal Default constructor called" RESET << std::endl;
}

/**
 * @brief Copy constructor for Animal.
 * Calls Animal copy assignment operator.
 * Prints a message when called.
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
 * Outputs a message indicating that the destructor has been called,
 * and handles cleanup for any resources acquired by the Animal object.
 */

Animal::~Animal(void)
{
	std::cout << RED "❌ Animal Destructor called" RESET << std::endl;
}

/**
 * @brief Copy assignment operator for Animal.
 *
 * This operator allows one Animal object to be assigned the values of another Animal object.
 * It checks for self-assignment and then copies the attributes from the provided Animal.
 * A message indicating the call to the copy assignment operator is displayed.
 *
 * @param rhs The Animal object to be assigned.
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
 * @brief Outputs the type of the Animal object.
 *
 * This function overloads the << operator to print the type of the Animal.
 *
 * @param out The output stream to write to.
 * @param rhs The Animal object to output.
 * @return The output stream after writing the type.
 */
std::ostream &operator<<(std::ostream &out, const Animal &rhs)
{
	out << rhs.getType();
	return (out);
}

/**
 * @brief Retrieves the type of the Animal.
 *
 * @return The type of the Animal, as a std::string.
 */
std::string Animal::getType(void) const
{
	return (this->type);
}
