#include "MyString.h"
#include <cstring> //strcpy

// defination of all the function declared in MyString.h
MyString::MyString()
{
    data = new char[1];
    length = 0;
    data[0] = '\0';
}

// para ctor
MyString::MyString(const char *str)
{
    data = new char[length + 1];
    length = strlen(str);
    strcpy(data, str);
}

// copy ctor
MyString::MyString(const MyString &other)
{
    data = new char[length + 1];
    length = other.length;
    strcpy(data, other.data);
}
// dtor
MyString::~MyString()
{
    delete[] data;
}

int MyString::size() const
{
    return length;
}

bool MyString::empty() const
{
    return length == 0;
}

const char *MyString::c_str() const
{
    return data;
}

char &MyString::operator[](int index)
{

    return data[index];
}

std::ostream &operator<<(std::ostream &os, const MyString &str)
{
    os << str.c_str();
    return os;
}