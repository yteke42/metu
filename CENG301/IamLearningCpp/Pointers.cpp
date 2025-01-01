#include <iostream>

using namespace std; 

int main(int argc, char const *argv[])
{
    int a, b, *p;

    a = b = 7;
    p = &a;
    cout << "*p = " << *p << endl;

    *p = 3;

    cout<< "*p = " << *p << endl;
    
    cout<< "a = " << a << endl;

    p = &b;

    *p = 2 * *p -a;

    cout << "a = " << a <<endl;


    cout<< "*p = " << *p << endl;

    cout << "b = " << b <<endl;

    cout << "a = " << a <<endl;

    return 0;
}
