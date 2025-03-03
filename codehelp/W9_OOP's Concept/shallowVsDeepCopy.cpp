#include <iostream>
using namespace std;

class abc
{
public:
    int x;
    int *y;

    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    // default dumb copy constructor : it does SHALLOW COPY
    abc(const abc &obj)
    {
        x = obj.x;
        y = obj.y;
    }

    // OUR SMART DEEP COPY
    // abc(const abc &obj)
    // {
    //     x = obj.x;
    //     y = new int(*obj.y);
    // }

    void print() const
    {
        printf("x:%d\nPTR Y:%p\nContent of Y(*y):%d\n\n", x, y, *y);
    }

    ~abc()
    {
        delete y;
    }
};

int main()
{
    // abc a(1, 2);
    // cout << "printing a\n";
    // a.print();

    // // abc b(a);
    // abc b = a; // call hora h copy constructor
    // cout << "printing b\n";
    // b.print();
    // *b.y = 20;
    // cout << "printing b\n";
    // b.print();

    // cout << "printing a\n";
    // a.print();

    abc *a = new abc(1, 2);
    abc b = *a;
    delete a;
    b.print();

    return 0;
}