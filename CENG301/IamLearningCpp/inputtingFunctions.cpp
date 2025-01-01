#include <iostream>

int getInput(){

    std::cout<<"Enter your number: ";

    int input{};
    std::cin>> input;

    return input;
}

int main()
{
    int number{getInput()};

    std::cout<<"You have entered " <<number;


    return 0;
}
