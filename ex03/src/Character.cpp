/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:33:17 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 17:48:38 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character(void) : _name("Default"), _count(0)
{
	//std::cout << GRN "✅ Character Default constructor called" RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		this->_unequipped[i] = NULL;
	}
}

Character::Character(std::string name) : _name(name), _count(0)
{
	//std::cout << GRN "✅ Character Name constructor called" RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		this->_unequipped[i] = NULL;
	}
}

Character::Character(const Character &rhs) : _name(rhs._name), _count(rhs._count)
{
	//std::cout << GRN "✅ Character Copy constructor called" RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (rhs._inventory[i])
			_inventory[i] = rhs._inventory[i]->clone();
		else
			_inventory[i] = NULL;
		_unequipped[i] = NULL; // Do not copy unequipped Materias
	}
}


Character::~Character(void)
{
	//std::cout << RED "❌ Character Destructor called" RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (this->_unequipped[i])
			delete this->_unequipped[i];
	}
}

Character &Character::operator=(const Character &rhs)
{
	//std::cout << GRN "✅ Character Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
	{
		// Clean up existing inventory and unequipped
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (this->_unequipped[i])
				delete this->_unequipped[i];
			this->_inventory[i] = NULL;
			this->_unequipped[i] = NULL;
		}
		// Copy name and count
		this->_name = rhs.getName();
		this->_count = rhs.getCount();
		// Deep copy inventory from rhs
		for (int i = 0; i < 4; i++)
		{
			if (rhs.getMateria(i))
				this->_inventory[i] = rhs.getMateria(i)->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (this->_name);
}

int Character::getCount(void) const
{
	return (this->_count);
}

AMateria *Character::getMateria(int idx) const
{
	if (idx >= 0 && idx < 4)
		return (this->_inventory[idx]);
	return (NULL);
}

AMateria *Character::getUnequipped(int idx) const
{
	if (idx >= 0 && idx < 4)
		return (this->_unequipped[idx]);
	return (NULL);
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !this->_inventory[idx])
	{
		std::cout << RED "❌ Character: Invalid index or no materia equipped" RESET<< std::endl;
		return;
	}
	this->_inventory[idx]->use(target);
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << RED "❌ Character: Cannot equip NULL materia" RESET << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			++(this->_count);
			std::cout << GRN "✅ Equipped " << m->getType() << " in slot " << i << RESET << std::endl;
			return;
		}
	}
	std::cout << RED "❌ No space to equip materia" RESET << std::endl;
	if (m)
		delete m; // Free the materia if it was not added to the inventory
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || this->_inventory[idx] == NULL)
	{
		std::cout << RED "❌ Character: Invalid slot or no materia to unequip" RESET << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_unequipped[i] == NULL)
		{
			this->_unequipped[i] = this->_inventory[idx];
			std::cout << YEL "🗑 Unequipped " << _inventory[idx]->getType() << " from slot " << idx << RESET << std::endl;
			this->_inventory[idx] = NULL;
			--(this->_count);
			return;
		}
	}
	std::cout << RED "❌ No space to unequip materia" RESET << std::endl;
}
