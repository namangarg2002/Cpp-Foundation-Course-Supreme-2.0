#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
private:
    string gf;

public:
    int id;
    int age;
    bool present;
    string name;
    int nos;

    // Constructor(ctor): Default Constructor
    // no khokhla Student
    // Student()
    // {
    //     cout << "Student ctor called" << endl;
    // }
    // Parametarized Constructor
    Student(int id, int age, bool present, string name, int nos, string gfname)
    {
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        this->gf = gfname;
        cout << "Student Parametarized ctor called" << endl;
    }

    Student(int id, int age, bool _present, string name, int nos)
    {
        this->id = id;
        this->age = age;
        this->present = _present;
        this->name = name;
        this->nos = nos;
        cout << "Student Parametarized ctor without gf called" << endl;
    }

    void study()
    {
        cout << "studing" << endl;
    }
    void sleep()
    {
        cout << "sleeping" << endl;
    }
    void bunk()
    {
        cout << "bunking" << endl;
    }

private:
    void gfchatting()
    {
        cout << "chatting" << endl;
    }
};

int main()
{
    // int id1, id2;
    // string name1, name2;
    // int age1, age2;
    // int nos1, nos2;
    // int marks1[5], marks2[2];

    // cout << sizeof(Student) << endl;
    // Student s1;
    // cout << s1.age << endl;
    // s1.name = "Goli";
    // s1.age = 12;
    // s1.id = 1;
    // s1.nos = 5;
    // s1.present = 1;

    // Student s2;
    // s2.name = "Chota Bheem";
    // s2.age = 11;
    // s2.id = 2;
    // s2.nos = 1;
    // s2.present = 0;

    // Student s1;

    Student s2(1, 12, 1, "chota Bheem", 1, "chutki");
    cout << s2.name << endl;
    cout << s2.id << endl;
    // cout << s2.gf << endl;

    Student s3(2, 15, 0, "lokesh", 5);
    cout << s3.name << endl;

    // Allocate on heap
    Student *s4 = new Student(3, 34, 1, "Chintu", 6);

    cout << s4->name << endl;
    cout << (*s4).name << endl;

    // need to deallocate heap memory due to memory leak
    delete s4; // No leak
    return 0;
}