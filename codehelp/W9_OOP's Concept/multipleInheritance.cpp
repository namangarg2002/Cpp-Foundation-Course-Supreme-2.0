#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    void walk()
    {
        cout << "Walking..." << endl;
    }
};

class Teacher : virtual public Person
{
public:
    void teach()
    {
        cout << "Teaching..." << endl;
    }
};

class Researcher : virtual public Person
{
public:
    void research()
    {
        cout << "Researching..." << endl;
    }
};

// Multiple Inheritance
class Professor : public Teacher, public Researcher
{
public:
    void bore()
    {
        cout << "Boring...";
    }
};

int main()
{
    Professor p;
    // Diamond Problem
    // Solution 1: Scope Resolution

    // p.Teacher::walk();
    // p.Researcher::walk();

    // Solution 2: Using Virtual

    p.walk();

    return 0;
}