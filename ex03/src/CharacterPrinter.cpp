/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharacterPrinter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:48:52 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:45:40 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

/**
 * @brief CenterAlign constructor.
 *
 * This constructor creates a CenterAlign object with the given string and width.
 */
std::ostream& operator<<(std::ostream& os, const CenterAlign& ca)
{
	int padding = (ca.width - ca.str.length()) / 2;

	if (padding < 0) padding = 0;

	os << std::string(padding, ' ') << ca.str
	<< std::string(ca.width - ca.str.length() - padding, ' ');

	return os;
}

/**
 * @brief Helper function to print a formatted header to the output stream.
 *
 * Outputs a bold cyan line with the character's name and a bold blue line
 * above and below it.
 *
 * @param out The output stream to write to.
 * @param rhs The Character object to print the header for.
 */
static void printHeader(std::ostream &out, const Character &rhs)
{
	const std::string boldLine = "=============================================";

	out << BBLU << boldLine << RESET << "\n"
		<< "  " << BCYN << rhs.getName() << "'s Materia Inventory" << RESET << "\n"
		<< BBLU << boldLine << RESET << "\n\n";
}

/**
 * @brief Helper function to print equipped Materias.
 *
 * Outputs the equipped Materias in a formatted table with slots.
 *
 * @param out The output stream to write to.
 * @param rhs The Character object containing the Materias.
 */
static void printEquippedMateria(std::ostream &out, const Character &rhs)
{
	const int slotWidth = 14;

	out << BGRN << "EQUIPPED MATERIA:" << RESET << "\n";
	out << BLU << "+--------------+--------------+--------------+--------------+" << RESET << "\n"
		<< BLU << "|" << RESET
		<< BCYN << CenterAlign("Slot 0", slotWidth) << RESET << BLU << "|" << RESET
		<< BCYN << CenterAlign("Slot 1", slotWidth) << RESET << BLU << "|" << RESET
		<< BCYN << CenterAlign("Slot 2", slotWidth) << RESET << BLU << "|" << RESET
		<< BCYN << CenterAlign("Slot 3", slotWidth) << RESET << BLU << "|" << RESET << "\n"
		<< BLU << "+--------------+--------------+--------------+--------------+" << RESET << "\n"
		<< BLU << "|" << RESET;

	bool anyEquipped = false;
	for (int i = 0; i < 4; i++)
	{
		AMateria *m = rhs.getMateria(i);
		if (m)
		{
			out << GRN << CenterAlign(m->getType(), slotWidth) << RESET;
			anyEquipped = true;
		}
		else
			out << RED << CenterAlign("[empty]", slotWidth) << RESET;
		if (i < 3)
			out << BLU << "|" << RESET;
		else
			out << BLU << "|" << RESET << std::endl;
	}
	out << BLU << "+--------------+--------------+--------------+--------------+" << RESET << "\n";
	if (!anyEquipped)
		out << MAG << "  No materia equipped\n" << RESET;
	out << std::endl;
}

/**
 * @brief Helper function to print unequipped Materias.
 *
 * Outputs the unequipped Materias in a formatted list with numbers.
 *
 * @param out The output stream to write to.
 * @param rhs The Character object containing the Materias.
 */
static void printUnequippedMateria(std::ostream &out, const Character &rhs)
{
	const int slotWidth = 14;

	out << BYEL << "UNEQUIPPED MATERIA:" << RESET << "\n";

	bool anyUnequipped = false;

	for (int i = 0; i < 4; i++)
	{
		AMateria *m = rhs.getUnequipped(i);
		if (m)
		{
			out << "  " << YEL << (i + 1) << ") " << std::left << std::setw(slotWidth)
				<< m->getType() << RESET;
			anyUnequipped = true;
			if ((i + 1) % 2 == 0) out << "\n";
		}
	}
	if (!anyUnequipped)
		out << MAG << "  No materia in storage\n" << RESET;
	else
		out << "\n";
}

/**
 * @brief Overloaded output operator for the Character class.
 *
 * This operator allows the Character object to be printed to an output stream.
 * It prints the character's name, equipped Materias, and unequipped Materias.
 *
 * @param out The output stream to write to.
 * @param rhs The Character object to output.
 * @return The output stream after writing the character information.
 */
std::ostream &operator<<(std::ostream &out, const Character &rhs)
{
	printHeader(out, rhs);
	printEquippedMateria(out, rhs);
	printUnequippedMateria(out, rhs);

	out << BBLU << "=============================================" << RESET << "\n\n";

	return out;
}
