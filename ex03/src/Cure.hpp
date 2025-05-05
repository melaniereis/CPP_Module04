/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:57:38 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/05 16:01:07 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << GRN "✅ Cure Default constructor called" RESET << std::endl;
}

Cure::Cure(const Cure &rhs) : AMateria(rhs)
{
	std::cout << GRN "✅ Cure Copy constructor called" RESET << std::endl;
	*this = rhs;
}

Cure::~Cure(void)
{
	std::cout << RED "❌ Cure Destructor called" RESET << std::endl;
}

Cure &Cure::operator=(const Cure &rhs)
{
	std::cout << GRN "✅ Cure Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << YEL "💊 * heals " << target.getName() << "'s wounds *" RESET << std::endl;
}
