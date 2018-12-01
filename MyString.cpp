#include "MyString.h"


MyString::MyString():str{nullptr}
{
#ifdef DEBUG
    std::cout << "empty constructor" << std::endl;
#endif
    str = new char[1];
    *str = '\0';
}

MyString::MyString(const char *s) : str{nullptr}
{
#ifdef DEBUG
    std::cout << "Constructor" << std::endl;
#endif
    if(s == nullptr){                    //empty str
        str = new char[1];               //create new str on heap
        *str = '\0';                     //null_terminator
    }
    else{   //not empty
        str = new char[std::strlen(s)+1];//new str on the heap
        std::strcpy(str,s);              //copy soure_str to this_str
    }
}

MyString::MyString(const MyString &source) : str{nullptr}
{
    str = new char[std::strlen(source.str)+1];
    std::strcpy(str,source.str);
}

MyString::~MyString()
{
#ifdef DEBUG
    if(str == nullptr){
        std::cout << "Destructor for MyString : nullptr" << std::endl;
    }
    else {
        std::cout << "Destructor for MyString : " << str << std::endl;
    }
#endif
    delete[] str;
}

void MyString::display() const
{
    std::cout << str << ":" << get_length() << std::endl;
}

unsigned int MyString::get_length() const
{
    return std::strlen(str);
}

const char *MyString::get_str() const
{
    return str;
}

MyString &MyString::operator=(const MyString &rhs)
{
#ifdef DEBUG
    std::cout << "Copy assingment" << std::endl;
#endif
    if(this == &rhs){                      //chek if self-assignment (current address = copy adress)
        return *this;
    }
    delete [] str;                            //deallocate current storage
    str = new char[std::strlen(rhs.str)+1];//create new str on the heap
    std::strcpy(str,rhs.str);              //copy soure_str to this_str
    return *this;
}

MyString &MyString::operator=(MyString &&source)
{
#ifdef DEBUG
    std::cout << "Move assingment" << std::endl;
#endif
    if(this == &source){  //self-assingment
        return *this;     //return current obj
    }

    delete [] str;        //deallocate current storage
    str = source.str;     //steal the pointer

    source.str = nullptr; //null out the source obj
    return *this;         //return current obj
}



void MyString::operator--() const
{
#ifdef DEBUG
    std::cout << "pre-decrement"<< std::endl;
#endif
    for(size_t i = 0; i < std::strlen(str); ++i){
        str[i] = std::tolower(str[i]);
    }
}

void MyString::operator++() const
{
#ifdef DEBUG
    std::cout << "pre-increment" << std::endl;
#endif
    for(size_t i = 0; i < std::strlen(str); ++i){
        str[i] = std::toupper(str[i]);
    }

}



bool MyString::operator!=(const MyString &rhs) const
{
    return !(std::strcmp(str, rhs.str)==0);
}




bool operator==(const MyString &lhs,const MyString &rhs){
#ifdef DEBUG
    std::cout << "global operator(==)" << std::endl;
#endif
    return std::strcmp(lhs.str, rhs.str)==0;
}
MyString operator-(const MyString &obj){
#ifdef DEBUG
    std::cout << "global operator(-)"<< std::endl;
#endif
    char *buff = new char[std::strlen(obj.str)+1];
    std::strcpy(buff,obj.str);
    for(size_t i = 0; i < std::strlen(buff); ++i){
        buff[i] = std::tolower(buff[i]);
    }
    MyString temp(buff);
    delete [] buff;
    return temp;
}
MyString operator+(const MyString &lhs,const MyString &rhs){
#ifdef DEBUG
    std::cout << "global Concatenation operator(+)" << std::endl;
#endif
    size_t buff_size = std::strlen(lhs.str)+std::strlen(rhs.str)+1;
    char *buff = new char[buff_size];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    MyString temp(buff);
    delete [] buff;
    return temp;
}
std::ostream &operator<<(std::ostream &os, const MyString &rhs){
#ifdef DEBUG
    std::cout << "output stream(<<)" << std::endl;
#endif
    os << rhs.str;
    return os;
}
std::istream &operator>>(std::istream &is, MyString &rhs){
#ifdef DEBUG
    std::cout << "input stream(>>)" << std::endl;
#endif
    char *buff = new char[1000];
    is >> buff;
    MyString temp(buff);
    rhs = temp;
    delete [] buff;
    return is;
}
