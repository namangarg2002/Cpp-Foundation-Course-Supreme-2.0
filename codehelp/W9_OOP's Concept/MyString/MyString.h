#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString
{
private:
    char *data; // pointer to char array data
    int length;

public:
    // default ctor
    MyString();

    // parametrarized ctor
    MyString(const char *str);

    // copy Constructor
    MyString(const MyString &other);

    // Destructor
    ~MyString();

    int size() const;

    bool empty() const;

    const char *c_str() const;

    char &operator[](int index);

    // overload insertion operator << for easy output
    friend std::ostream &operator<<(std::ostream &os, const MyString &str);
};

#endif // MYSTRING_H