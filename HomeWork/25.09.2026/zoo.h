#pragma once
#include <string>

class Animal
{
public:
    Animal();
    ~Animal();
    Animal(const Animal& other);
    Animal(Animal&& other);
    Animal& operator=(const Animal& other);
    Animal& operator=(Animal&& other);
    

    virtual void MakeSound();
    virtual void AskForFood();
    virtual void Move();
};

class Dog : public Animal
{
public:
    Dog();
    ~Dog();
    Dog(const Dog& dog);
    Dog(Dog&& dog);
    Dog& operator=(const Dog& dog);
    Dog& operator=(Dog&& dog);

    virtual void MakeSound() override;
    virtual void AskForFood() override;
    virtual void Move() override;
};

class Cat : public Animal
{
public:
    Cat();
    ~Cat();
    Cat(const Cat& cat);
    Cat(Cat&& cat);
    Cat& operator=(const Cat& cat);
    Cat& operator=(Cat&& cat);

    virtual void MakeSound() override;
    virtual void AskForFood() override;
    virtual void Move() override;
};

class Cow : public Animal
{
public:
    Cow();
    ~Cow();
    Cow(const Cow& cow);
    Cow(Cow&& cow);
    Cow& operator=(const Cow& cow);
    Cow& operator=(Cow&& cow);

    virtual void MakeSound() override;
    virtual void AskForFood() override;
    virtual void Move() override;
};

class Parrot : public Animal
{
public:
    Parrot();
    ~Parrot();
    Parrot(const Parrot& parrot);
    Parrot(Parrot&& parrot);
    Parrot& operator=(const Parrot& parrot);
    Parrot& operator=(Parrot&& parrot);

    virtual void MakeSound() override;
    virtual void AskForFood() override;
    virtual void Move() override;
};