/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:57:38 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/05 16:03:09 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << GRN "✅ Ice Default constructor called" RESET << std::endl;
}

Ice::Ice(const Ice &rhs) : AMateria(rhs)
{
	std::cout << GRN "✅ Ice Copy constructor called" RESET << std::endl;
	*this = rhs;
}

Ice::~Ice(void)
{
	std::cout << RED "❌ Ice Destructor called" RESET << std::endl;
}

Ice &Ice::operator=(const Ice &rhs)
{
	std::cout << GRN "✅ Ice Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

AMateria *Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << YEL "🧊 * shoots an ice bolt at " << target.getName() << " *" RESET << std::endl;
}
