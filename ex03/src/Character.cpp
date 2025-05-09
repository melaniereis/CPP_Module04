/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:33:17 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:43:29 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

/**
 * @brief Default constructor for the Character class.
 *
 * This constructor creates a Character with the name "Default" and initializes
 * the inventory and unequipped storage with NULL pointers.
 */
Character::Character(void) : _name("Default"), _count(0)
{
	//std::cout << GRN "✅ Character Default constructor called" RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		this->_unequipped[i] = NULL;
	}
}

/**
 * @brief Character constructor with a name.
 *
 * This constructor initializes a Character object with the given name. The
 * count is set to 0, and the inventory and unequipped Materia arrays are
 * initialized to NULL. The name is copied internally.
 *
 * @param name The name of the Character.
 */
Character::Character(std::string name) : _name(name), _count(0)
{
	//std::cout << GRN "✅ Character Name constructor called" RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		this->_unequipped[i] = NULL;
	}
}

/**
 * @brief Copy constructor for the Character class.
 *
 * This constructor creates a deep copy of a Character object. It copies the
 * name and count of the source object, and creates a deep copy of the
 * inventory and unequipped Materia stored in the source object. It does not
 * copy the unequipped Materia.
 *
 * @param rhs The Character object to copy from.
 */
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

/**
 * @brief Copy assignment operator for the Character class.
 *
 * This operator allows one Character object to be assigned the values of another Character object.
 *
 * @param rhs The Character object to assign from.
 * @return A reference to the current object.
 */
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

/**
 * @brief Retrieves the name of the Character.
 *
 * This function returns the name of the Character as a string.
 *
 * @return The name of the Character.
 */
std::string const &Character::getName(void) const
{
	return (this->_name);
}

/**
 * @brief Retrieves the count of equipped Materia in the Character's inventory.
 *
 * @return The number of Materia currently equipped.
 */
int Character::getCount(void) const
{
	return (this->_count);
}

/**
 * @brief Retrieves the Materia at the specified index in the inventory.
 *
 * If the index is invalid, this function returns NULL. Otherwise, it returns the
 * Materia at the specified index in the inventory.
 *
 * @param idx The index of the inventory slot to retrieve (0 to 3).
 */
AMateria *Character::getMateria(int idx) const
{
	if (idx >= 0 && idx < 4)
		return (this->_inventory[idx]);
	return (NULL);
}

/**
 * @brief Retrieves the Materia at the specified index in the unequipped storage.
 *
 * If the index is invalid, this function returns NULL. Otherwise, it returns the
 * Materia at the specified index in the unequipped storage.
 *
 * @param idx The index of the unequipped storage slot to retrieve (0 to 3).
 */
AMateria *Character::getUnequipped(int idx) const
{
	if (idx >= 0 && idx < 4)
		return (this->_unequipped[idx]);
	return (NULL);
}

/**
 * @brief Uses the Materia at the specified inventory slot on the target.
 *
 * This function attempts to use a Materia from the given index in the inventory
 * on the specified target character. If the index is invalid or the slot is empty,
 * an error message is printed. Otherwise, the Materia's use function is called.
 *
 * @param idx The index of the inventory slot to use (0 to 3).
 * @param target The target character on which to use the Materia.
 */
void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !this->_inventory[idx])
	{
		std::cout << RED "❌ Character: Invalid index or no materia equipped" RESET<< std::endl;
		return;
	}
	this->_inventory[idx]->use(target);
}

/**
 * equip
 *
 * Equips a Materia in the first available slot in the Character's inventory.
 * If there is no space available, an error message is printed and the materia is freed.
 *
 * @param m The Materia to equip.
 */
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
			this->_inventory[i] = m->clone();
			++(this->_count);
			std::cout << GRN "✅ Equipped " << m->getType() << " in slot " << i << RESET << std::endl;
			delete m;
			return;
		}
	}
	std::cout << RED "❌ No space to equip materia" RESET << std::endl;
	if (m)
		delete m; // Free the materia if it was not added to the inventory
}

/**
 * @brief Unequips a Materia from the specified inventory slot and moves it to unequipped storage.
 *
 * This function attempts to move a Materia from the given index in the inventory
 * to the first available slot in the unequipped storage. If the index is invalid
 * or the slot is empty, an error message is printed. If there is no space in the
 * unequipped storage, an error message is printed.
 *
 * @param idx The index of the inventory slot to unequip from (0 to 3).
 */
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
