/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:17:36 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:22:30 by meferraz         ###   ########.fr       */
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
void wrongHierarchyTest();
void printFinalMessage();

// ─────────────────────────────────────────────
//                  Entry Point
// ─────────────────────────────────────────────

/**
 * @brief Program entry point for the Animal Simulation.
 *
 * This function initiates the simulation by calling various test functions
 * that demonstrate polymorphism, object creation, copying, and hierarchy.
 *
 * Functions called:
 * - subjectTest: Demonstrates basic polymorphic behavior with Dog and Cat.
 * - arrayTest: Tests polymorphic behavior within an array of animals.
 * - deepCopyTest: Validates deep copying of objects.
 * - wrongHierarchyTest: Examines behavior with an incorrect hierarchy.
 * - printFinalMessage: Outputs a final message.
 */
int main(void)
{
	std::cout << BGRN "\n\n🌟===== 🐦 🐪 💮 ANIMAL SIMULATION 🌻 🌲 🐺 =====🌟\n\n" RESET;

	subjectTest();
	arrayTest();
	deepCopyTest();
	wrongHierarchyTest();
	printFinalMessage();

	return 0;
}

// ─────────────────────────────────────────────
//             Subject Demonstration
// ─────────────────────────────────────────────

/**
 * @brief Tests polymorphic behavior with Dog and Cat objects.
 *
 * This function creates pointers to Animal, Dog, and Cat objects and
 * demonstrates polymorphic behavior by calling makeSound on the Animal
 * pointer. It then deletes all created objects to ensure proper memory
 * management.
 */
void subjectTest()
{
	SEPARATOR("1. Original Subject Test");

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n🔊 Testing polymorphic sounds:\n";
	std::cout << "Dog says: ";
	j->makeSound();
	std::cout << "Cat says: ";
	i->makeSound();

	delete j;
	delete i;
}

// ─────────────────────────────────────────────
//                  Array Test
// ─────────────────────────────────────────────

/**
 * @brief Tests polymorphism with an array of Animal objects.
 *
 * This function creates an array of Animal objects, populates it with
 * alternating Dog and Cat objects, and then calls makeSound on each.
 * The output will be the appropriate sound for each animal type.
 *
 * The function also illustrates object creation and destruction, ensuring
 * proper memory management by deleting all created objects.
 */
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

/**
 * @brief Validates deep copying of Dog objects.
 *
 * This function demonstrates the deep copy of a Dog object by creating a
 * copy of the original Dog, modifying the copy, and then verifying that
 * the original Dog's state remains unchanged.
 *
 * Output will show the original Dog's first idea, the copied Dog's first
 * idea, and the modified copy's first idea. The final output will show
 * the original Dog's first idea after the copy is destroyed, ensuring that
 * the original Dog's state was not modified by the copy.
 */
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
//          Wrong Hierarchy Demonstration
// ─────────────────────────────────────────────

/**
 * @brief Demonstrates non-polymorphic behavior by calling makeSound on a WrongAnimal pointer pointing to a WrongCat object.
 *
 * This function shows that the WrongAnimal class does not use virtual functions,
 * and therefore calling makeSound on a WrongAnimal pointer pointing to a WrongCat
 * object will not produce the expected behavior.
 *
 * Output will show the WrongAnimal sound instead of the WrongCat sound.
 */
void wrongHierarchyTest()
{
	SEPARATOR("4. Non-Polymorphic Behavior");

	const WrongAnimal* fakeCat = new WrongCat();
	std::cout << "\n🚫 WrongAnimal sound: ";
	fakeCat->makeSound(); // Demonstrates non-virtual behavior
	delete fakeCat;
}

// ─────────────────────────────────────────────
//                  Final Message
// ─────────────────────────────────────────────

/**
 * Outputs a final message to the console indicating that the simulation
 * is complete.
 *
 * This function is called at the end of the main function to output a final
 * message to the console, which includes a green checkmark and a party popper
 * emoji.
 */
void printFinalMessage()
{
	std::cout << "\n" << BGRN "🎉✅ Simulation complete! 🎉\n\n" RESET;
}
