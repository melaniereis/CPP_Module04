/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:55:38 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/05 15:05:51 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << GRN "✅ WrongCat Default constructor called" RESET << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &rhs)
{
	std::cout << GRN "✅ WrongCat Copy constructor called" RESET << std::endl;
	*this = rhs;
}

WrongCat::~WrongCat(void)
{
	std::cout << RED "❌ WrongCat Destructor called" RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << GRN "✅ WrongCat Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << MAG "🐱 WrongCat sound"  RESET << std::endl;
}
