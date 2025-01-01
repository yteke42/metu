#include <iostream>

int max(int x, int y){
    return (x<y) ? y : x;
}

double max(double x, double y){ return (x<y) ? y : x;}


int main()
{
    std::cout << "Enter two int: "<<std::endl;
    double x{},y{};
    std::cin >> x;
    std::cin >> y;

    std::cout << "The max is: "<<max(x,y)<< std::endl;
    return 0;
}


