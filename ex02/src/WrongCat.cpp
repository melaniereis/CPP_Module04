/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:55:38 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:38:44 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

/**
 * Default constructor for WrongCat.
 *
 * Initializes a new instance of the WrongCat class by calling the
 * constructor of the base class WrongAnimal. It sets the type of
 * the WrongCat to "WrongCat" and outputs a message indicating
 * that the default constructor has been called.
 */
WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << GRN "✅ WrongCat Default constructor called" RESET << std::endl;
	type = "WrongCat";
}

/**
 * Copy constructor for WrongCat.
 *
 * This constructor creates a new WrongCat object as a copy of an existing one.
 * It outputs a message indicating that the copy constructor has been called.
 * The assignment operator is used to copy the properties of the existing object.
 *
 * @param rhs The WrongCat object to copy from.
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
 * Outputs the sound associated with the WrongCat.
 *
 * This function prints a WrongCat-specific sound ("WrongCat sound") to the console.
 */
void WrongCat::makeSound(void) const
{
	std::cout << MAG "🐱 WrongCat sound"  RESET << std::endl;
}
