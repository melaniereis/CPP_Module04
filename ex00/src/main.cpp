/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:17:36 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:13:28 by meferraz         ###   ########.fr       */
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
void objectSlicingTest();
void wrongAnimalTest();
void copyConstructorTest();
void assignmentOperatorTest();
void outputOperatorTest();
void printFinalMessage();

// ─────────────────────────────────────────────
//                  Entry Point
// ─────────────────────────────────────────────

/**
 * Program entry point.
 *
 * Simulates some animal behaviors and tests object creation/copying.
 *
 * 1. Subject Test: Tests the Animal base class and its derived classes.
 * 2. Array Test: Tests the animal array.
 * 3. Object Slicing Test: Tests object slicing.
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
	objectSlicingTest();
	wrongAnimalTest();
	copyConstructorTest();
	assignmentOperatorTest();
	outputOperatorTest();
	printFinalMessage();

	return 0;
}

// ─────────────────────────────────────────────
//             Subject Demonstration
// ─────────────────────────────────────────────

/**
 * @brief Demonstrates basic polymorphism with Animal, Dog, and Cat classes.
 *
 * This function creates instances of Animal, Dog, and Cat, then outputs
 * their types and sounds. It showcases polymorphic behavior by calling
 * makeSound on pointers to the base class.
 *
 * The function also illustrates object creation and destruction, ensuring
 * proper memory management by deleting all created objects.
 */
void subjectTest()
{
	SEPARATOR("Subject Test");

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); // Will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;
}

// ─────────────────────────────────────────────
//              Polymorphism Test
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
	SEPARATOR("Polymorphism Array Test");
	const int size = 4;
	Animal* animals[size];

	// Create alternating Dogs and Cats
	for (int i = 0; i < size; ++i) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// Demonstrate polymorphic behavior
	for (int i = 0; i < size; ++i) {
		std::cout << "Animal " << i+1 << " type: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	// Cleanup
	for (int i = 0; i < size; ++i) {
		delete animals[i];
	}
}

// ─────────────────────────────────────────────
//             Object Slicing Test
// ─────────────────────────────────────────────

/**
 * @brief Demonstrates object slicing with Animal and Cat classes.
 *
 * This function illustrates the concept of object slicing by assigning
 * a Cat object to an Animal object, resulting in the loss of the Cat-specific
 * behavior. It outputs the type and sound of both the real Cat and the
 * sliced Animal to showcase the effect of slicing. The real Cat retains
 * its specific behavior, while the sliced Animal exhibits base class behavior.
 */
void objectSlicingTest()
{
	SEPARATOR("Object Slicing Test");
	Cat realCat;
	Animal slicedAnimal = realCat; // Object slicing occurs here

	std::cout << "Real cat type:    " << realCat.getType() << std::endl;
	std::cout << "Sliced animal type: " << slicedAnimal.getType() << std::endl;

	std::cout << "Real cat sound:    ";
	realCat.makeSound();

	std::cout << "Sliced animal sound: ";
	slicedAnimal.makeSound(); // Should call Animal's version
}

// ─────────────────────────────────────────────
//          Non-Virtual Behavior Test
// ─────────────────────────────────────────────

/**
 * @brief Demonstrates non-virtual behavior with WrongAnimal and WrongCat classes.
 *
 * This function creates instances of WrongAnimal and WrongCat, then outputs
 * their types and sounds. It showcases non-virtual behavior by calling
 * makeSound on pointers to the base class, which should output the base
 * class's sound, instead of the derived class's sound.
 *
 * The function also illustrates object creation and destruction, ensuring
 * proper memory management by deleting all created objects.
 */
void wrongAnimalTest()
{
	SEPARATOR("Wrong Animal Test");
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongJ = new WrongCat();

	std::cout << "Wrong animal type: " << wrongJ->getType() << std::endl;
	std::cout << "Expected WrongCat sound ➔ But actual: ";
	wrongJ->makeSound(); // Should output WrongAnimal's sound
	std::cout << "Wrong animal type: " << wrongMeta->getType() << std::endl;
	std::cout << "Expected WrongAnimal sound: ";
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongJ;
}

// ─────────────────────────────────────────────
//             Copy Constructor Test
// ─────────────────────────────────────────────

/**
 * @brief Tests the copy constructor with Dog objects.
 *
 * This function creates a Dog object and creates a copy of it using the copy
 * constructor. It then outputs the type and sound of both the original and
 * copied Dog objects to demonstrate that the copy was successful.
 */
void copyConstructorTest()
{
	SEPARATOR("Copy Constructor Test");
	Dog originalDog;
	Dog copiedDog(originalDog);

	std::cout << "Original dog type: " << originalDog.getType() << std::endl;
	std::cout << "Copied dog type:   " << copiedDog.getType() << std::endl;
	std::cout << "Copied dog sound:  ";
	copiedDog.makeSound();
}

// ─────────────────────────────────────────────
//           Assignment Operator Test
// ─────────────────────────────────────────────

/**
 * @brief Tests the assignment operator with Cat objects.
 *
 * This function creates two Cat objects, cat1 and cat2, and assigns cat1 to
 * cat2. It then outputs the types and sounds of both Cat objects to demonstrate
 * that the assignment operator copied the values correctly.
 */
void assignmentOperatorTest()
{
	SEPARATOR("Assignment Operator Test");
	Cat cat1;
	Cat cat2;

	cat2 = cat1;

	std::cout << "Cat1 type: " << cat1.getType() << std::endl;
	std::cout << "Cat2 type: " << cat2.getType() << std::endl;
	std::cout << "Cat2 sound: ";
	cat2.makeSound();
}

// ─────────────────────────────────────────────
//           Output Operator Test
// ─────────────────────────────────────────────

/**
 * @brief Tests the output operator for all animal types.
 *
 * This function creates instances of all animal types and outputs them
 * using the overloaded output operator. It then prints the output
 * to the console to demonstrate that the output operator is working
 * correctly.
 */
void outputOperatorTest()
{
	SEPARATOR("Output Operator Test");
	Animal animal;
	Dog dog;
	Cat cat;
	WrongAnimal wrongAnimal;
	WrongCat wrongCat;

	std::cout << "Base animal:     " << animal << std::endl;
	std::cout << "Dog:             " << dog << std::endl;
	std::cout << "Cat:             " << cat << std::endl;
	std::cout << "Wrong animal:    " << wrongAnimal << std::endl;
	std::cout << "Wrong cat:       " << wrongCat << std::endl;
}

// ─────────────────────────────────────────────
//                  Final Message
// ─────────────────────────────────────────────

/**
 * @brief Outputs a final message to the console indicating that the simulation
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
