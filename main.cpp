#include <iostream>
#include <MyString.h>
using namespace std;

int main()
{
    MyString hello = "Hello, ";//constructor
    MyString world = "World!";//constructor
    MyString result;//empty constructor
    result = hello + world;//move constructor
    cout << result << endl;

    --result;//predecrement
    cout << result << endl;
    ++result;//preincrement
    cout << result << endl;
    cout << (hello==world) << endl;//comparison
    MyString bad_result = hello + "fucking " + world;
    cout << bad_result << endl;
    return 0;
}
