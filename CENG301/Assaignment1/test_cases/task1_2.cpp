#include <iostream>
using namespace std;

#include "ImaginaryPoint.h"

int main() {
    ImaginaryPoint *i1 = new ImaginaryPoint(0, 0);
    ImaginaryPoint *i2 = new ImaginaryPoint(1, 1);

    ImaginaryPoint i3 = (*i1) + (*i2);
    ImaginaryPoint i4 = (*i1) * (*i2);



    cout<<(i1->get_real_part())<<endl;
    cout<<(i1->get_imaginary_part())<<endl;
    cout<<(i1->get_magnitude_squared())<<endl;
    cout<<endl;

    cout<<(i2->get_real_part())<<endl;
    cout<<(i2->get_imaginary_part())<<endl;
    cout<<(i2->get_magnitude_squared())<<endl;
    cout<<endl;

    cout<<(i3.get_real_part())<<endl;
    cout<<(i3.get_imaginary_part())<<endl;
    cout<<(i3.get_magnitude_squared())<<endl;
    cout<<endl;

    cout<<(i4.get_real_part())<<endl;
    cout<<(i4.get_imaginary_part())<<endl;
    cout<<(i4.get_magnitude_squared())<<endl;
    cout<<endl;
    return 0;
}
