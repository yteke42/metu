#include <iostream>
using namespace std;

void printReverse(const char* str){
    if (*str){
        printReverse(str+1);
        cout <<*str;
    }
}


int main()
{
    printReverse("hello");
    return 0;
}
