#include <iostream>

int main() {

    std::cout <<"Enter an integer: ";
    
    int number1{};
    std::cin >> number1;

    std::cout <<"Enter another integer: ";  
    
    int number2{};
    std::cin >>number2;

    std::cout <<number1<<" + "<<number2<<" is "<< number1+number2<<"\n";
    std::cout <<number1<<" - "<<number2<<" is "<< number1-number2;

    return 0;
}