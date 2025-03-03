#include <iostream>
#include <string>
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
    int *v;

    // Constructor(ctor): Default Constructor
    // no khokhla Student
    Student()
    {
        cout << "Student ctor called" << endl;
    }
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
        this->v = new int(10);
        cout << "Student Parametarized ctor without gf called" << endl;
    }

    // Copy Ctor
    Student(const Student &srcobj)
    {
        cout << "Student Copy ctor called" << endl;
        this->name = srcobj.name;
        this->age = srcobj.age;
        this->gf = srcobj.gf;
        this->nos = srcobj.nos;
        this->present = srcobj.present;
        this->id = srcobj.id;
    }

    // getter / Setter
    string getGfName()
    {
        return gf;
        // return this->gf;
    }

    void setGfName(string gf)
    {
        // authentication
        this->gf = gf;
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

    ~Student()
    {
        cout << "Student dtor called" << endl;
    }

private:
    void gfchatting()
    {
        cout << "chatting" << endl;
    }

    void cheating()
    {
        cout << "cheating" << endl;
    }
};

int main()
{
    // // copy Ctor
    // // Student s1(1, 12, 1, "Chota Bheem", 1, "Chutki");
    // // Student s2 = s1;
    // // Student s2;
    // // s2 = s1;
    // Student s2 = s1;

    // cout << s1.name << endl;
    // cout << s2.name << endl;

    // Destructor

    Student s1(1, 12, 1, "Chota Bheem", 1, "Chutki");
    cout << s1.name << endl;

    // getter/setter
    cout << s1.getGfName() << endl;
    s1.setGfName("Indumati");
    cout << s1.getGfName() << endl;

    return 0;
}