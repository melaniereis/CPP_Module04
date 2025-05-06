/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:17:36 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 17:07:48 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/MateriaSource.hpp"


// ─────────────────────────────────────────────
//                Format Macros
// ─────────────────────────────────────────────
#define SEPARATOR(txt) std::cout << "\n"                                              \
								<< WHT "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"      \
								<< "🔹 " << txt << "\n"                              \
								<< "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" RESET "\n" \
								<< std::endl

// ─────────────────────────────────────────────
//              Function Prototypes
// ─────────────────────────────────────────────
void subjectTest();
void extraTests();
void printFinalMessage();


// ─────────────────────────────────────────────
//                  Entry Point
// ─────────────────────────────────────────────
int main()
{
	std::cout << BGRN "\n\n🌟===== Interfaces Simulation =====🌟\n\n" RESET;

	subjectTest();
	extraTests();
	printFinalMessage();

	return 0;
}

// ─────────────────────────────────────────────
//             Subject Demonstration
// ─────────────────────────────────────────────
void subjectTest()
{
	SEPARATOR("Subject Test");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

// ─────────────────────────────────────────────
//               Extra Tests
// ─────────────────────────────────────────────
void extraTests()
{
	SEPARATOR("Extra Tests");

	// Test MateriaSource learning and creating
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); // Learn another Ice

	// Try to learn more than 4 Materias
	for (int i = 0; i < 3; ++i)
		src->learnMateria(new Cure()); // Should only learn up to 4

	// Create Materias
	AMateria* ice = src->createMateria("ice");
	AMateria* cure = src->createMateria("cure");
	AMateria* unknown = src->createMateria("unknown"); // Should return NULL

	// Test Character equipping
	Character hero("Hero");
	std::cout << "Initial state:\n" << hero << std::endl;

	hero.equip(ice);
	hero.equip(cure);
	hero.equip(src->createMateria("ice"));
	hero.equip(src->createMateria("cure"));
	std::cout << "After equipping 4 Materias:\n" << hero << std::endl;

	// Try to equip more than 4 Materias
	hero.equip(src->createMateria("ice")); // Should not equip
	std::cout << "After trying to equip a 5th Materia:\n" << hero << std::endl;

	// Use equipped Materias
	Character target("Target");
	hero.use(0, target);
	hero.use(1, target);
	hero.use(2, target);
	hero.use(3, target);
	hero.use(4, target); // Invalid index

	// Unequip Materias
	hero.unequip(1);
	hero.unequip(3);
	hero.unequip(5); // Invalid index
	std::cout << "After unequipping slots 1 and 3:\n" << hero << std::endl;

	// Re-equip new Materias
	hero.equip(src->createMateria("cure"));
	hero.equip(src->createMateria("ice"));
	std::cout << "After re-equipping:\n" << hero << std::endl;

	// Use again
	hero.use(0, target);
	hero.use(1, target);
	hero.use(2, target);
	hero.use(3, target);

	// Test deep copy
	Character copy = hero;
	std::cout << "Copy of hero:\n" << copy << std::endl;
	copy.use(0, target);
	copy.use(1, target);

	// Modify original and check copy
	hero.unequip(0);
	hero.equip(src->createMateria("cure"));
	std::cout << "After modifying hero:\n" << hero << std::endl;
	std::cout << "Copy remains unchanged:\n" << copy << std::endl;
	hero.use(0, target);
	copy.use(0, target); // Should still have the original Materia

	// Cleanup
	delete src;
	if (unknown)
		delete unknown; // Should be NULL, but check to avoid leaks
}

// ─────────────────────────────────────────────
//                  Final Message
// ─────────────────────────────────────────────
void printFinalMessage()
{
	std::cout << "\n" << BGRN "🎉✅ Simulation complete! 🎉\n\n" RESET;
}
