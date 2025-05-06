/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:02:30 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 16:56:59 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	//std::cout << GRN "✅ MateriaSource Default constructor called" RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::~MateriaSource(void)
{
	//std::cout << GRN "❌ MateriaSource Default destructor called" RESET << std::endl;
}
MateriaSource::MateriaSource(const MateriaSource &rhs)
{
	//std::cout << GRN "✅ MateriaSource Copy constructor called" RESET << std::endl;
	*this = rhs;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	//std::cout << GRN "✅ MateriaSource Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->_materias[i]; // Free existing materias
			if (rhs._materias[i])
				this->_materias[i] = rhs._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << RED "❌ MateriaSource: Invalid materia" RESET << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materias[i])
		{
			this->_materias[i] = m;
			return ;
		}
	}
	if (m)
		delete m; // Free the materia if it was not added to the source
	std::cout << RED "❌ MateriaSource: No more slots available" RESET << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	std::cout << RED "❌ MateriaSource: Materia not found" RESET << std::endl;
	return (NULL);
}

