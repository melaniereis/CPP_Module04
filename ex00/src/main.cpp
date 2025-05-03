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
void objectSlicingTest();
void wrongAnimalTest();
void copyConstructorTest();
void assignmentOperatorTest();
void outputOperatorTest();
void printFinalMessage();

// ─────────────────────────────────────────────
//                  Entry Point
// ─────────────────────────────────────────────
int main()
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
void printFinalMessage()
{
	std::cout << "\n" << BGRN "🎉✅ Simulation complete! 🎉\n\n" RESET;
}
