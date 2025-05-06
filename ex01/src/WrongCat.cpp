/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:55:38 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:24:12 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

/**
 * Default constructor for WrongCat.
 *
 * This constructor will set the type of the WrongCat to "WrongCat".
 * It will also display a message indicating that the default constructor has been called.
 */
WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << GRN "✅ WrongCat Default constructor called" RESET << std::endl;
	type = "WrongCat";
}

/**
 * Copy constructor for WrongCat.
 *
 * This constructor creates a new WrongCat object as a copy of an existing WrongCat object.
 * It initializes the new WrongCat with the same attributes as the provided WrongCat.
 * A message indicating the call to the copy constructor is displayed.
 *
 * @param rhs The WrongCat object to be copied.
 */
WrongCat::WrongCat(const WrongCat &rhs)
{
	std::cout << GRN "✅ WrongCat Copy constructor called" RESET << std::endl;
	*this = rhs;
}

/**
 * Destructor for WrongCat.
 *
 * This destructor is responsible for releasing any resources
 * allocated by the WrongCat object. It outputs a message
 * indicating that the destructor has been called.
 */
WrongCat::~WrongCat(void)
{
	std::cout << RED "❌ WrongCat Destructor called" RESET << std::endl;
}

/**
 * Copy assignment operator for WrongCat.
 *
 * This operator allows one WrongCat object to be assigned the values of another WrongCat object.
 * It checks for self-assignment and then copies the attributes from the provided WrongCat.
 * A message indicating the call to the copy assignment operator is displayed.
 *
 * @param rhs The WrongCat object to be assigned.
 * @return A reference to the current object.
 */
WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << GRN "✅ WrongCat Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

/**
 * @brief Outputs the sound associated with the WrongCat.
 *
 * This function prints a WrongCat-specific sound to the console.
 */

void WrongCat::makeSound(void) const
{
	std::cout << MAG "🐱 WrongCat sound"  RESET << std::endl;
}
