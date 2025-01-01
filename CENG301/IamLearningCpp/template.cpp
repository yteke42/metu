#include <iostream>

template <typename T>

T max(T x, T y){
    return (x<y) ? y : x;
}


int main()
{
    std::cout << "Enter two int: "<<std::endl;
    double x{},y{};
    std::cin >> x;
    std::cin >> y;

    std::cout << "The max is: "<<max(x,y)<< std::endl;
    return 0;
}



