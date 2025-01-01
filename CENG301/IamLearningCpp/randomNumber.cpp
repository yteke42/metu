#include "random"
#include <iostream>

int main()
{
    std::mt19937 rng(std::random_device{}());

    std::uniform_int_distribution<int> distribution(1, 10);

    for(int i{0}; i<20; i++){
        int random_number = distribution(rng);

        std::cout << random_number << "\t";

    }

    
    return 0;
}
