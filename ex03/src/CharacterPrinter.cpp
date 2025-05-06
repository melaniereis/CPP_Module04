/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharacterPrinter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:48:52 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 17:52:29 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

// CenterAlign operator<<
std::ostream& operator<<(std::ostream& os, const CenterAlign& ca)
{
	int padding = (ca.width - ca.str.length()) / 2;

	if (padding < 0) padding = 0;

	os << std::string(padding, ' ') << ca.str
	<< std::string(ca.width - ca.str.length() - padding, ' ');

	return os;
}

// Helper function to print the header
static void printHeader(std::ostream &out, const Character &rhs)
{
	const std::string boldLine = "=============================================";

	out << BBLU << boldLine << RESET << "\n"
		<< "  " << BCYN << rhs.getName() << "'s Materia Inventory" << RESET << "\n"
		<< BBLU << boldLine << RESET << "\n\n";
}

// Helper function to print equipped Materias
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

// Helper function to print unequipped Materias
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

// Main operator<< for Character
std::ostream &operator<<(std::ostream &out, const Character &rhs)
{
	printHeader(out, rhs);
	printEquippedMateria(out, rhs);
	printUnequippedMateria(out, rhs);

	out << BBLU << "=============================================" << RESET << "\n\n";

	return out;
}
