/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 09:17:36 by meferraz          #+#    #+#             */
/*   Updated: 2025-05-03 09:17:36 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

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
void arrayTest();
void deepCopyTest();
void printFinalMessage();

// ─────────────────────────────────────────────
//                  Entry Point
// ─────────────────────────────────────────────
int main()
{
	std::cout << BGRN "\n\n🌟===== 🐦 🐪 💮 ANIMAL SIMULATION 🌻 🌲 🐺 =====🌟\n\n" RESET;

	subjectTest();
	arrayTest();
	deepCopyTest();
	printFinalMessage();

	return 0;
}

// ─────────────────────────────────────────────
//             Subject Demonstration
// ─────────────────────────────────────────────
void subjectTest()
{
	SEPARATOR("Subject Test");

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
}

// ─────────────────────────────────────────────
//                  Array Test
// ─────────────────────────────────────────────
void arrayTest()
{
	SEPARATOR("Array Test");

	const Animal* animals[4];

	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();

	// Demonstrate polymorphism
	std::cout << "\nAnimal Orchestra:\n";
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Animal " << i+1 << " (" << animals[i]->getType() << "): ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < 4; i++)
		delete animals[i];
}

// ─────────────────────────────────────────────
//             Deep Copy Test
// ─────────────────────────────────────────────
void deepCopyTest()
{
	SEPARATOR("Deep Copy Test");

	Dog originalDog;
	{
		Dog copiedDog(originalDog);

		std::cout << "\nOriginal Dog type: " << originalDog.getType() << std::endl;
		std::cout << "Copied Dog type:   " << copiedDog.getType() << std::endl;

		std::cout << "\nOriginal Dog first idea: "
				<< originalDog.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied Dog first idea:    "
				<< copiedDog.getBrain()->getIdea(0) << std::endl;
				std::cout << "\nOriginal Dog second idea: "
				<< originalDog.getBrain()->getIdea(1) << std::endl;
		std::cout << "Copied Dog second idea:    "
				<< copiedDog.getBrain()->getIdea(1) << std::endl;
	}

	std::cout << "\nOriginal Dog type after copiedDog goes out of scope: "
			<< originalDog.getType() << std::endl;
}

// ─────────────────────────────────────────────
//                  Final Message
// ─────────────────────────────────────────────
void printFinalMessage()
{
	std::cout << "\n" << BGRN "🎉✅ Simulation complete! 🎉\n\n" RESET;
}
