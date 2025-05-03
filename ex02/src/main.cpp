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

	//const Animal* meta = new Animal();
	SEPARATOR("1. Original Subject Test");

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n🔊 Testing polymorphic sounds:\n";
	std::cout << "Dog says: ";
	j->makeSound();
	std::cout << "Cat says: ";
	i->makeSound();
	//meta->makeSound();

	//delete meta;
	delete i;
	delete j;
}

// ─────────────────────────────────────────────
//                  Array Test
// ─────────────────────────────────────────────
void arrayTest()
{
	SEPARATOR("2. Polymorphic Array Test");

	const Animal* animals[4];

	// Half dogs, half cats
	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();

	std::cout << "\n🗣️  Array sound check:\n";
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Animal " << i << ": ";
		animals[i]->makeSound();
	}

	// Cleanup
	for (int i = 0; i < 4; i++)
		delete animals[i];
}

// ─────────────────────────────────────────────
//             Deep Copy Test
// ─────────────────────────────────────────────
void deepCopyTest()
{
	SEPARATOR("3. Deep Copy Validation");

	Dog original;
	std::cout << "\n🧠 Original Dog's first idea: "
			<< original.getBrain()->getIdea(0) << std::endl;

	{ // Scope for copied dog
		Dog copy(original);
		std::cout << "📝 Copied Dog's first idea:  "
				<< copy.getBrain()->getIdea(0) << std::endl;

		// Modify copy's idea
		copy.getBrain()->setRandomIdeas();
		std::cout << "🔄 Modified copy's first idea: "
				<< copy.getBrain()->getIdea(0) << std::endl;
	} // Copy destroyed here

	std::cout << "\n🔍 Original Dog's first idea after copy destruction: "
			<< original.getBrain()->getIdea(0) << std::endl;
}

// ─────────────────────────────────────────────
//                  Final Message
// ─────────────────────────────────────────────
void printFinalMessage()
{
	std::cout << "\n" << BGRN "🎉✅ Simulation complete! 🎉\n\n" RESET;
}
