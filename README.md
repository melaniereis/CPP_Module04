# 🦆 CPP Module 04 - Subtype Polymorphism, Abstract Classes, Interfaces

<div align="center">

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)
![Module](https://img.shields.io/badge/Module-04-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

*Mastering Polymorphism, Abstract Classes, and Interface Design*

</div>

## 📖 Overview

**CPP Module 04** explores the pinnacle of object-oriented programming: **subtype polymorphism**, **abstract classes**, and **interface design**. Through animal hierarchies and a magical materia system, you'll master virtual functions, pure virtual functions, deep copying, and complex interface implementations that form the backbone of professional C++ design.

### 🎯 Learning Objectives

- Master virtual functions and dynamic dispatch
- Implement pure virtual functions and abstract classes
- Design and implement interfaces (pure abstract classes)
- Understand and implement deep copying for complex objects
- Explore subtype polymorphism and runtime type identification
- Practice memory management in polymorphic hierarchies
- Learn interface segregation and dependency inversion principles

## 💡 Key Concepts Introduced

- **Virtual Functions**: Runtime method resolution and polymorphic behavior
- **Pure Virtual Functions**: Abstract methods that must be implemented by derived classes
- **Abstract Classes**: Classes with at least one pure virtual function
- **Interfaces**: Pure abstract classes defining contracts
- **Deep Copying**: Proper copying of objects containing dynamic resources
- **Subtype Polymorphism**: Treating derived objects as base types
- **Virtual Destructors**: Ensuring proper cleanup in inheritance hierarchies

## 🚀 Exercises

### 🐾 Exercise 00: Polymorphism
**Files**: `Animal.cpp`, `Animal.hpp`, `Dog.cpp`, `Dog.hpp`, `Cat.cpp`, `Cat.hpp`, `WrongAnimal.cpp`, `WrongAnimal.hpp`, `WrongCat.cpp`, `WrongCat.hpp`, `main.cpp`

Introduction to polymorphism through an animal hierarchy, demonstrating:
- Virtual functions and dynamic dispatch
- Proper virtual destructor usage
- Contrasting virtual vs non-virtual behavior
- Base class pointer polymorphism

**Animal Base Class**:
```cpp
class Animal {
public:
    Animal(void);
    Animal(const Animal &rhs);
    virtual ~Animal(void);                    // Virtual destructor
    Animal &operator=(const Animal &rhs);

    virtual void makeSound(void) const;       // Virtual function
    std::string getType(void) const;

protected:
    std::string type;
};
```

**Derived Classes**:
```cpp
class Dog : public Animal {
public:
    Dog(void);
    Dog(const Dog &rhs);
    virtual ~Dog(void);
    Dog &operator=(const Dog &rhs);

    void makeSound(void) const override;      // Override virtual function
};

class Cat : public Animal {
public:
    Cat(void);
    Cat(const Cat &rhs);
    virtual ~Cat(void);
    Cat &operator=(const Cat &rhs);

    void makeSound(void) const override;      // Override virtual function
};
```

**Polymorphic Behavior**:
```cpp
void Dog::makeSound(void) const {
    std::cout << "🐕 Woof! Woof!" << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "🐱 Meow! Meow!" << std::endl;
}
```

**Wrong Classes (Non-Virtual Demonstration)**:
```cpp
class WrongAnimal {
public:
    WrongAnimal(void);
    ~WrongAnimal(void);                       // Non-virtual destructor
    void makeSound(void) const;               // Non-virtual function
};

class WrongCat : public WrongAnimal {
public:
    WrongCat(void);
    ~WrongCat(void);
    void makeSound(void) const;               // Hides base method
};
```

**Usage Example**:
```cpp
// Correct polymorphic behavior
Animal* animals[4];
animals[0] = new Dog();
animals[1] = new Cat();

for (int i = 0; i < 2; i++) {
    animals[i]->makeSound();  // Calls correct overridden method
    delete animals[i];        // Calls correct destructor
}

// Wrong behavior (no polymorphism)
WrongAnimal* wrong = new WrongCat();
wrong->makeSound();           // Calls WrongAnimal::makeSound()
delete wrong;                 // Only calls WrongAnimal destructor
```

**Key Learning Points**:
- Virtual function table (vtable) mechanism
- Dynamic vs static binding
- Importance of virtual destructors
- Base class pointer polymorphism
- Method hiding vs method overriding

---

### 🧠 Exercise 01: I Don't Want to Set the World on Fire
**Files**: `Animal.cpp`, `Animal.hpp`, `Dog.cpp`, `Dog.hpp`, `Cat.cpp`, `Cat.hpp`, `Brain.cpp`, `Brain.hpp`, `main.cpp`

Advanced polymorphism with deep copying and composition, showcasing:
- Object composition with dynamic allocation
- Deep copying implementation
- Memory management in complex hierarchies
- Resource management through RAII

**Brain Class** (Component):
```cpp
class Brain {
public:
    Brain(void);
    Brain(const Brain &rhs);
    virtual ~Brain(void);
    Brain &operator=(const Brain &rhs);

    void setRandomIdeas(void);
    void printIdeas(void) const;
    void setIdea(int index, const std::string &idea);
    std::string getIdea(int index) const;

private:
    std::string ideas[100];                   // Array of 100 ideas
};
```

**Enhanced Animal Classes with Brain Composition**:
```cpp
class Dog : public Animal {
public:
    Dog(void);
    Dog(const Dog &rhs);                      // Deep copy constructor
    virtual ~Dog(void);
    Dog &operator=(const Dog &rhs);           // Deep copy assignment

    void makeSound(void) const override;
    Brain* getBrain(void) const;

private:
    Brain* brain;                             // Dynamically allocated brain
};

class Cat : public Animal {
public:
    Cat(void);
    Cat(const Cat &rhs);                      // Deep copy constructor
    virtual ~Cat(void);
    Cat &operator=(const Cat &rhs);           // Deep copy assignment

    void makeSound(void) const override;
    Brain* getBrain(void) const;

private:
    Brain* brain;                             // Dynamically allocated brain
};
```

**Deep Copy Implementation**:
```cpp
Dog::Dog(void) : Animal() {
    type = "Dog";
    brain = new Brain();                      // Allocate brain
    std::cout << "🐕 Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &rhs) : Animal(rhs) {
    brain = new Brain(*rhs.brain);            // Deep copy brain
    std::cout << "🐕 Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
    if (this != &rhs) {
        Animal::operator=(rhs);
        delete brain;                         // Clean up old brain
        brain = new Brain(*rhs.brain);       // Deep copy new brain
    }
    return *this;
}

Dog::~Dog(void) {
    delete brain;                             // Clean up brain
    std::cout << "🐕 Dog Destructor called" << std::endl;
}
```

**Memory Management Test**:
```cpp
void testDeepCopy() {
    Dog original;
    original.getBrain()->setIdea(0, "I love bones!");

    Dog copy = original;                      // Deep copy
    copy.getBrain()->setIdea(0, "I love treats!");

    // Original and copy should have different ideas
    std::cout << "Original: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy: " << copy.getBrain()->getIdea(0) << std::endl;
}
```

**Array Test**:
```cpp
void testPolymorphicArray() {
    Animal* animals[4];

    for (int i = 0; i < 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = 2; i < 4; i++) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < 4; i++) {
        animals[i]->makeSound();
        delete animals[i];                    // Proper cleanup
    }
}
```

**Key Learning Points**:
- Deep copying vs shallow copying
- Memory management in composition
- Resource Acquisition Is Initialization (RAII)
- Proper cleanup in inheritance hierarchies
- Object lifecycle management

---

### 🔒 Exercise 02: Abstract Class
**Files**: `Animal.cpp`, `Animal.hpp`, `Dog.cpp`, `Dog.hpp`, `Cat.cpp`, `Cat.hpp`, `Brain.cpp`, `Brain.hpp`, `main.cpp`

Pure virtual functions and abstract classes, demonstrating:
- Pure virtual function declaration
- Abstract class instantiation prevention
- Enforced implementation in derived classes
- Interface contract specification

**Abstract Animal Class**:
```cpp
class Animal {
public:
    Animal(void);
    Animal(const Animal &rhs);
    virtual ~Animal(void);
    Animal &operator=(const Animal &rhs);

    virtual void makeSound(void) const = 0;   // Pure virtual function
    std::string getType(void) const;

protected:
    std::string type;
};
```

**Pure Virtual Function Benefits**:
- **Enforced Implementation**: Derived classes MUST implement `makeSound()`
- **Abstract Base**: Cannot instantiate `Animal` directly
- **Contract Definition**: Defines interface that all derived classes must follow
- **Compile-Time Safety**: Compiler prevents incomplete implementations

**Compilation Behavior**:
```cpp
// This will NOT compile:
Animal animal;                                // Error: Cannot instantiate abstract class

// This WILL compile:
Animal* animal = new Dog();                   // Polymorphic instantiation
animal->makeSound();                          // Calls Dog::makeSound()
delete animal;
```

**Implementation Requirement**:
```cpp
class Dog : public Animal {
public:
    // ... constructors, destructors ...

    void makeSound(void) const override;      // MUST implement this

private:
    Brain* brain;
};

// If Dog doesn't implement makeSound(), compilation fails
```

**Key Learning Points**:
- Pure virtual function syntax (`= 0`)
- Abstract class characteristics
- Compile-time interface enforcement
- Polymorphic instantiation patterns
- Interface contract compliance

---

### ✨ Exercise 03: Interface & Recap
**Files**: `AMateria.cpp`, `AMateria.hpp`, `ICharacter.hpp`, `Character.cpp`, `Character.hpp`, `IMateriaSource.hpp`, `MateriaSource.cpp`, `MateriaSource.hpp`, `Ice.cpp`, `Ice.hpp`, `Cure.cpp`, `Cure.hpp`, `main.cpp`

Complex interface design with multiple inheritance patterns, showcasing:
- Pure interface design (all pure virtual functions)
- Multiple interface implementation
- Abstract base classes with partial implementation
- Complex object interaction systems

**Interface Definitions**:

#### `ICharacter` Interface:
```cpp
class ICharacter {
public:
    virtual ~ICharacter(void) {}
    virtual std::string const &getName(void) const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};
```

#### `IMateriaSource` Interface:
```cpp
class IMateriaSource {
public:
    virtual ~IMateriaSource(void) {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};
```

**Abstract Base Class**:
```cpp
class AMateria {
public:
    AMateria(std::string const & type);
    AMateria(void);
    AMateria(const AMateria &rhs);
    virtual ~AMateria(void);
    AMateria &operator=(const AMateria &rhs);

    std::string const & getType(void) const;
    virtual AMateria* clone(void) const = 0;  // Pure virtual
    virtual void use(ICharacter& target);     // Default implementation

protected:
    std::string type;
};
```

**Concrete Materia Classes**:
```cpp
class Ice : public AMateria {
public:
    Ice(void);
    Ice(const Ice &rhs);
    virtual ~Ice(void);
    Ice &operator=(const Ice &rhs);

    AMateria* clone(void) const override;
    void use(ICharacter& target) override;
};

class Cure : public AMateria {
public:
    Cure(void);
    Cure(const Cure &rhs);
    virtual ~Cure(void);
    Cure &operator=(const Cure &rhs);

    AMateria* clone(void) const override;
    void use(ICharacter& target) override;
};
```

**Interface Implementations**:

#### `Character` Class:
```cpp
class Character : public ICharacter {
public:
    Character(std::string const &name);
    Character(const Character &rhs);
    virtual ~Character(void);
    Character &operator=(const Character &rhs);

    std::string const &getName(void) const override;
    void equip(AMateria* m) override;
    void unequip(int idx) override;
    void use(int idx, ICharacter& target) override;

private:
    std::string name;
    AMateria* inventory[4];                   // Fixed-size inventory
    static std::vector<AMateria*> floor;      // Shared dropped items
};
```

#### `MateriaSource` Class:
```cpp
class MateriaSource : public IMateriaSource {
public:
    MateriaSource(void);
    MateriaSource(const MateriaSource &rhs);
    virtual ~MateriaSource(void);
    MateriaSource &operator=(const MateriaSource &rhs);

    void learnMateria(AMateria* materia) override;
    AMateria* createMateria(std::string const & type) override;

private:
    AMateria* templates[4];                   // Known materia templates
};
```

**Complex Usage Example**:
```cpp
void demonstrateInterface() {
    // Create materia source
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Create character
    ICharacter* me = new Character("me");

    // Create and equip materia
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Create target
    ICharacter* bob = new Character("bob");

    // Use materia on target
    me->use(0, *bob);  // * shoots an ice bolt at bob *
    me->use(1, *bob);  // * heals bob's wounds *

    // Cleanup
    delete bob;
    delete me;
    delete src;
}
```

**Advanced Features**:
- **Inventory Management**: Fixed 4-slot inventory with unequip/drop mechanics
- **Materia Factory**: Template-based materia creation system
- **Memory Management**: Proper cleanup of dropped items
- **Interface Polymorphism**: Multiple interface implementation
- **Clone Pattern**: Deep copying through virtual clone methods

**Key Learning Points**:
- Interface design principles
- Multiple interface implementation
- Abstract factory pattern
- Clone pattern for polymorphic copying
- Complex object lifecycle management
- Interface segregation principle
- Dependency inversion principle

## 🛠️ Compilation

Each exercise includes a Makefile with standard targets:

```bash
# Compile the program
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

**Compilation flags**:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## 🎮 How to Run

### Exercise 00 - Polymorphism
```bash
cd ex00
make
./animal
```

### Exercise 01 - I Don't Want to Set the World on Fire
```bash
cd ex01
make
./brain
```

### Exercise 02 - Abstract Class
```bash
cd ex02
make
./abstract
```

### Exercise 03 - Interface & Recap
```bash
cd ex03
make
./materia
```

## 🧪 Testing Examples

### Polymorphism Test
```cpp
// Test virtual function behavior
Animal* animals[] = { new Dog(), new Cat() };
for (int i = 0; i < 2; i++) {
    std::cout << "Type: " << animals[i]->getType() << std::endl;
    animals[i]->makeSound();  // Dynamic dispatch
    delete animals[i];        // Virtual destructor
}
```

### Deep Copy Test
```cpp
// Test brain deep copying
Dog original;
original.getBrain()->setIdea(0, "Original thought");

Dog copy = original;  // Should create separate brain
copy.getBrain()->setIdea(0, "Copy thought");

// Verify independence
assert(original.getBrain()->getIdea(0) != copy.getBrain()->getIdea(0));
```

### Abstract Class Test
```cpp
// This should NOT compile in ex02:
// Animal animal;  // Error: Cannot instantiate abstract class

// This should work:
Animal* animal = new Dog();
animal->makeSound();  // Calls Dog::makeSound()
delete animal;
```

### Interface Test
```cpp
// Test materia system
IMateriaSource* source = new MateriaSource();
source->learnMateria(new Ice());

ICharacter* wizard = new Character("Gandalf");
AMateria* spell = source->createMateria("ice");
wizard->equip(spell);

ICharacter* target = new Character("Balrog");
wizard->use(0, *target);  // Cast ice spell on Balrog
```

## 🏗️ Project Structure

```
CPP_Module04/
├── README.md
├── ex00/                    # Polymorphism
│   ├── Makefile
│   ├── inc/
│   │   ├── ansi.h
│   │   ├── Animal.hpp
│   │   ├── Dog.hpp
│   │   ├── Cat.hpp
│   │   ├── WrongAnimal.hpp
│   │   └── WrongCat.hpp
│   └── src/
│       ├── Animal.cpp
│       ├── Dog.cpp
│       ├── Cat.cpp
│       ├── WrongAnimal.cpp
│       ├── WrongCat.cpp
│       └── main.cpp
├── ex01/                    # I Don't Want to Set the World on Fire
│   ├── Makefile
│   ├── inc/
│   │   ├── ansi.h
│   │   ├── Animal.hpp
│   │   ├── Dog.hpp
│   │   ├── Cat.hpp
│   │   └── Brain.hpp
│   └── src/
│       ├── Animal.cpp
│       ├── Dog.cpp
│       ├── Cat.cpp
│       ├── Brain.cpp
│       └── main.cpp
├── ex02/                    # Abstract Class
│   ├── Makefile
│   ├── inc/
│   │   ├── ansi.h
│   │   ├── Animal.hpp (abstract)
│   │   ├── Dog.hpp
│   │   ├── Cat.hpp
│   │   └── Brain.hpp
│   └── src/
│       ├── Animal.cpp
│       ├── Dog.cpp
│       ├── Cat.cpp
│       ├── Brain.cpp
│       └── main.cpp
└── ex03/                    # Interface & Recap
    ├── Makefile
    ├── inc/
    │   ├── ansi.h
    │   ├── AMateria.hpp
    │   ├── ICharacter.hpp
    │   ├── IMateriaSource.hpp
    │   ├── Character.hpp
    │   ├── MateriaSource.hpp
    │   ├── Ice.hpp
    │   └── Cure.hpp
    └── src/
        ├── AMateria.cpp
        ├── Character.cpp
        ├── MateriaSource.cpp
        ├── Ice.cpp
        ├── Cure.cpp
        └── main.cpp
```

## 💡 Key Takeaways

1. **Virtual Functions**: Enable runtime polymorphism and dynamic dispatch
2. **Pure Virtual Functions**: Create abstract classes and enforce interface contracts
3. **Interface Design**: Define clear contracts for class behavior
4. **Deep Copying**: Essential for objects managing dynamic resources
5. **Memory Management**: Critical in polymorphic hierarchies
6. **Abstract Factory Pattern**: Flexible object creation through interfaces
7. **SOLID Principles**: Interface segregation and dependency inversion

## 🎯 Skills Developed

- ✅ Virtual function implementation and usage
- ✅ Pure virtual function and abstract class design
- ✅ Interface definition and implementation
- ✅ Deep copying in complex object hierarchies
- ✅ Polymorphic memory management
- ✅ Abstract factory pattern implementation
- ✅ Clone pattern for polymorphic copying
- ✅ Complex object interaction design

## ⚠️ Common Pitfalls & Solutions

1. **Missing Virtual Destructors**: Always make destructors virtual in base classes
2. **Shallow Copying**: Implement deep copying for objects with dynamic resources
3. **Pure Virtual Confusion**: Remember that pure virtual functions make classes abstract
4. **Interface Bloat**: Keep interfaces focused and cohesive (Interface Segregation)
5. **Memory Leaks**: Careful cleanup in polymorphic hierarchies
6. **Slicing**: Avoid passing polymorphic objects by value

## 🔗 Design Patterns Introduced

### Abstract Factory Pattern
- **Purpose**: Create families of related objects without specifying concrete classes
- **Implementation**: `MateriaSource` creating different materia types
- **Benefits**: Flexible object creation, easy extension

### Clone Pattern
- **Purpose**: Create copies of polymorphic objects
- **Implementation**: `AMateria::clone()` virtual method
- **Benefits**: Deep copying without knowing concrete type

### Strategy Pattern
- **Purpose**: Define family of algorithms and make them interchangeable
- **Implementation**: Different materia effects through virtual `use()` method
- **Benefits**: Runtime behavior selection, easy extension

## 🔗 SOLID Principles Applied

1. **Single Responsibility**: Each class has one reason to change
2. **Open-Closed**: Classes open for extension, closed for modification
3. **Liskov Substitution**: Derived classes are substitutable for base classes
4. **Interface Segregation**: Focused, cohesive interfaces
5. **Dependency Inversion**: Depend on abstractions, not concretions

## 🔗 Next Steps

After mastering Module 04, you'll be ready to tackle:
- **Module 05**: Exception handling mechanisms
- **Module 06**: C++ casts and type conversions
- **Module 07**: Templates and generic programming

---

<div align="center">

*"Polymorphism is not just about code reuse, it's about designing flexible, maintainable systems."*

**Module 04 Complete** ✨ | **Previous**: [← Module 03](https://github.com/melaniereis/CPP_Module03/) | **Next**: [Module 05 →](https://github.com/melaniereis/CPP_Module005)

</div>
