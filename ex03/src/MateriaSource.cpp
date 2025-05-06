/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:02:30 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:52:20 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

/**
 * MateriaSource::MateriaSource(void)
 *
 * Default constructor for the MateriaSource class.
 *
 * This constructor initializes the internal array of Materias to NULL.
 *
 * This constructor prints a green constructor message to the console, indicating that it was called.
 */
MateriaSource::MateriaSource(void)
{
	//std::cout << GRN "✅ MateriaSource Default constructor called" RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

/**
 * MateriaSource::~MateriaSource(void)
 *
 * The destructor for the MateriaSource class, which cleans up the resources used by the object.
 * This function is called when a MateriaSource object is destroyed.
 *
 * This destructor is virtual, so it can be overridden by derived classes.
 *
 * This destructor prints a green destructor message to the console, indicating that it was called.
 */
MateriaSource::~MateriaSource(void)
{
	//std::cout << GRN "❌ MateriaSource Default destructor called" RESET << std::endl;
}
MateriaSource::MateriaSource(const MateriaSource &rhs)
{
	//std::cout << GRN "✅ MateriaSource Copy constructor called" RESET << std::endl;
	*this = rhs;
}

/**
 * @brief Copy assignment operator for MateriaSource.
 *
 * This operator allows one MateriaSource object to be assigned the values of another MateriaSource object.
 * It checks for self-assignment and then copies the attributes from the provided MateriaSource.
 *
 * @param rhs The MateriaSource object to be assigned.
 * @return A reference to the current object.
 */
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

/**
 * @brief Learn a new Materia.
 *
 * This function stores the given Materia in the first available slot in the
 * MateriaSource's inventory. If no slots are available, an error message is
 * printed and the Materia is freed.
 *
 * @param m The Materia to learn.
 */
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

/**
 * @brief Creates a new AMateria object of the specified type.
 *
 * This function searches through the stored Materias to find one that matches
 * the given type. If a match is found, it creates and returns a clone of the
 * matching Materia. If no matching Materia is found, an error message is printed
 * and a NULL pointer is returned.
 *
 * @param type The type of the Materia to create.
 * @return A pointer to the newly created AMateria object, or NULL if no matching
 * Materia is found.
 */
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

