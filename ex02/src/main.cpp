/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:17:36 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:35:59 by meferraz         ###   ########.fr       */
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
 * @brief Program entry point.
 *
 * Simulates some animal behaviors and tests object creation/copying.
 *
 * 1. Subject Test: Tests the Animal base class and its derived classes.
 * 2. Array Test: Tests the animal array.
 * 3. Deep Copy Test: Tests deep copying of objects.
 * 4. Wrong Animal Test: Tests WrongAnimal and WrongCat classes.
 * 5. Copy Constructor Test: Tests the copy constructor.
 * 6. Assignment Operator Test: Tests the assignment operator.
 * 7. Output Operator Test: Tests the output operator.
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
 * @brief Tests the Animal base class and its derived classes.
 *
 * This function creates instances of Dog and Cat, then outputs
 * their types and sounds. It showcases polymorphic behavior by calling
 * makeSound on pointers to the base class.
 *
 * The function also illustrates object creation and destruction, ensuring
 * proper memory management by deleting all created objects.
 */
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

/**
 * @brief Tests polymorphic behavior with an array of Animal objects.
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
 * @brief Validates deep copying of Dog objects and their Brain instances.
 *
 * This function demonstrates the deep copy mechanism by creating an original
 * Dog object and a copy of it. It shows that the Brain of the copied Dog can
 * be modified without affecting the original Dog's Brain, thus validating the
 * deep copy process. The function outputs the first idea from each Dog's Brain
 * before and after the modification, ensuring that the original object's
 * state remains unchanged even after the copy is destroyed.
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
 * @brief Demonstrates non-polymorphic behavior with WrongAnimal and WrongCat classes.
 *
 * This function creates a WrongAnimal pointer pointing to a WrongCat object,
 * then calls makeSound on the pointer. The output will be the WrongAnimal's
 * sound, not the WrongCat's sound, demonstrating non-virtual behavior.
 *
 * The function also illustrates object creation and destruction, ensuring
 * proper memory management by deleting the created object.
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
