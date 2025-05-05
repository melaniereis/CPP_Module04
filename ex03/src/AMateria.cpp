/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:49:45 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/05 15:56:14 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << GRN "✅ AMateria Type constructor called" RESET << std::endl;
}

AMateria::AMateria(void) : _type("unknown")
{
	std::cout << GRN "✅ AMateria Default constructor called" RESET << std::endl;
}

AMateria::AMateria(const AMateria &rhs)
{
	std::cout << GRN "✅ AMateria Copy constructor called" RESET << std::endl;
	*this = rhs;
}

AMateria::~AMateria(void)
{
	std::cout << GRN "❌ AMateria Default destructor called" RESET << std::endl;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	std::cout << GRN "✅ AMateria Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}
void AMateria::use(ICharacter &target)
{
	std::cout << CYN "AMateria used on " << target.getName() << RESET << std::endl;
}


