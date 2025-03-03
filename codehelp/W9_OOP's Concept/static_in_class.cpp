#include <iostream>
using namespace std;

// class abc
// {
// public:
//     int x, y;
//     void print() const
//     {
//         // this pointer
//         cout << this->x << " " << this->y << endl;
//     }
// };

// class abc
// {
// public:
//     static int x, y; // static data menber
//     void print() const
//     {
//         // this pointer
//         cout << x << " " << y << endl;
//     }
// };

class abc
{
public:
    int x, y;
    abc() : x{0}, y{0} {}
    static void print() // static member function
    {
        // this pointer
        printf("I am in static %s\n", __FUNCTION__);
    }
};

int main()
{
    // abc obj1 = {1, 2};
    // abc obj2 = {4, 5};
    // obj1.print();
    // obj2.print();

    // abc obj1;
    // obj1.x = 1;
    // obj1.y = 2;
    // obj1.print();
    // abc obj2;
    // obj2.x = 10;
    // obj2.y = 20;
    // obj2.print();

    // abc obj1;
    // abc::x = 1;
    // abc::y = 2;
    // abc::print();
    // abc obj2;
    // abc::x = 10;
    // abc::y = 20;
    // abc::print();

    abc obj1;

    abc::print();
    abc obj2;

    abc::print();
    return 0;
}