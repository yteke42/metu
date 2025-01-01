#include "random"
#include <iostream>

bool randomNumber(){

    std::mt19937 rng(std::random_device{}());

    std::uniform_int_distribution<int> distribution(0, 1);

    int random_number = distribution(rng);

    return random_number;
}


int main()
{
    int random_number = randomNumber();
    if(random_number == 1){
        std::cout << "True" << "\n";
    } else{
        std::cout << "False" << "\n";
    }
    return 0;
}
