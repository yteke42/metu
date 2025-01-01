#include <iostream>

int doubleNumber(int number){

    return 2*number;
}

int getInput(){

    std::cout << "Enter an integer: ";
    
    int input{};
    std::cin >> input;

    return input; 
}

int main() {
    
    std::cout << doubleNumber(getInput());
    return 0;
}
