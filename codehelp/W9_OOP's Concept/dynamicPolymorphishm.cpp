#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        cout << "Animal making sound" << endl;
    }
    virtual ~Animal()
    {
        cout << "~Animal dtor" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Dog Barking" << endl;
    }
    ~Dog()
    {
        cout << "~Dog dtor" << endl;
    }
};

class Cat : public Animal
{
public:
    void sound() override
    {
        cout << "Cat Meowing" << endl;
    }
    ~Cat()
    {
        cout << "~Cat dtor" << endl;
    }
};

class Parrot : public Animal
{
public:
    void sound() override
    {
        cout << "Parrot Chirping" << endl;
    }
};

void sound(Animal *animal)
{
    animal->sound(); // Polymorphic
    // animal ka sound is behaving as per required object allocated at runime
}

int main()
{
    Animal *animal = new Dog();
    sound(animal);

    animal = new Cat();
    sound(animal);

    animal = new Parrot();
    sound(animal);

    delete animal;
    return 0;
}