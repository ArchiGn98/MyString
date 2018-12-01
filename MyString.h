#ifndef MYSTRING_H
#define MYSTRING_H
/* define DEBUG if you want to start debugging or watch the programm flow */
#define DEBUG
#include <iostream>
#include <cstring>

class MyString
{
    friend bool operator==(const MyString &lhs,const MyString &rhs);
    friend MyString operator-(const MyString &obj);
    friend MyString operator+(const MyString &lhs,const MyString &rhs);
    friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
    friend std::istream &operator>>(std::istream &is, const MyString &rhs);
private:
    char *str;
public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &source);
    ~MyString();
    void display() const;
    unsigned int get_length() const;
    const char *get_str() const;
    MyString &operator=(const MyString &rhs);
    MyString &operator=(MyString &&rhs);
    void operator--()const;
    void operator++()const;
    bool operator!=(const MyString &rhs)const;

};

#endif // MYSTRING_H
