#include <iostream>
#include "zoo.h"


Animal::Animal() = default;
Animal::~Animal() = default;
Animal::Animal(const Animal& other) = default;
Animal::Animal(Animal&& other) = default;
Animal& Animal::operator=(const Animal& other) = default;
Animal& Animal::operator=(Animal&& other) = default;

void Animal::MakeSound()
{
    std::cout << "Silence" << std::endl;
}

void Animal::AskForFood()
{
    std::cout << "I want to eat" << std::endl;
}

void Animal::Move()
{
    std::cout << "I move like an animal" << std::endl;
}

// Собака

Dog::Dog() : Animal() {}
Dog::~Dog() = default;
Dog::Dog(const Dog& dog) = default;
Dog::Dog(Dog&& dog) = default;
Dog& Dog::operator=(const Dog& dog) = default;
Dog& Dog::operator=(Dog&& dog) = default;

void Dog::MakeSound()
{
    std::cout << "Gav-gav" << std::endl;
}

void Dog::AskForFood()
{
    std::cout << "Give me some meat" << std::endl;
}

void Dog::Move()
{
    std::cout << "I run on four legs and wag my tail" << std::endl;
}

// Кот

Cat::Cat() : Animal() {}
Cat::~Cat() = default;
Cat::Cat(const Cat& cat) = default;
Cat::Cat(Cat&& cat) = default;
Cat& Cat::operator=(const Cat& cat) = default;
Cat& Cat::operator=(Cat&& cat) = default;

void Cat::MakeSound()
{
    std::cout << "May" << std::endl;
}

void Cat::AskForFood()
{
    std::cout << "Give me some milk" << std::endl;
}

void Cat::Move()
{
    std::cout << "I walk gracefully and purr" << std::endl;
}

// Корова

Cow::Cow() : Animal() {}
Cow::~Cow() = default;
Cow::Cow(const Cow& cow) = default;
Cow::Cow(Cow&& cow) = default;
Cow& Cow::operator=(const Cow& cow) = default;
Cow& Cow::operator=(Cow&& cow) = default;

void Cow::MakeSound()
{
    std::cout << "Moo" << std::endl;
}

void Cow::AskForFood()
{
    std::cout << "Give me some grass" << std::endl;
}

void Cow::Move()
{
    std::cout << "I walk slowly on the meadow" << std::endl;
}

// Попугай

Parrot::Parrot() : Animal() {}
Parrot::~Parrot() = default;
Parrot::Parrot(const Parrot& parrot) = default;
Parrot::Parrot(Parrot&& parrot) = default;
Parrot& Parrot::operator=(const Parrot& parrot) = default;
Parrot& Parrot::operator=(Parrot&& parrot) = default;

void Parrot::MakeSound()
{
    std::cout << "Prrrrivet" << std::endl;
}

void Parrot::AskForFood()
{
    std::cout << "Give me some seeds" << std::endl;
}

void Parrot::Move()
{
    std::cout << "I fly" << std::endl;
}