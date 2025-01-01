#include <iostream>
using namespace std;

#include "BottomKList.h"
#include "ImaginaryPoint.h"

int main() {
    BottomKList<int,3> l1;
    int *a = new int(1),
        *b = new int(0),
        *c = new int(5),
        *d = new int(3),
        *e = new int(7),
        *f = new int(-1);
    l1.addElement(a);
    // now l1.arr is [a, nullptr, nullptr]
    l1.addElement(b);
    // now l1.arr is [b, a, nullptr]
    l1.addElement(c);
    // now l1.arr is [b, a, c]
    l1.addElement(d);
    // now l1.arr is [b, a, d]
    l1.addElement(e);
    // now l1.arr is [b, a, d]
    l1.addElement(f);
    // now l1.arr is [f, b, a]
    int* l1_zero = l1.getBottomXthElement(0);
    int* l1_one = l1.getBottomXthElement(1);
    int* l1_two = l1.getBottomXthElement(2);

    cout<<(*l1_zero)<<endl;
    cout<<(*l1_one)<<endl;
    cout<<(*l1_two)<<endl;

    BottomKList<ImaginaryPoint,2> l2;

    ImaginaryPoint *i1 = new ImaginaryPoint(3,4);
    ImaginaryPoint *i2 = new ImaginaryPoint(5,12);
    ImaginaryPoint *i3 = new ImaginaryPoint(1,1);
    ImaginaryPoint *i4 = new ImaginaryPoint(2,4);
    ImaginaryPoint *i5 = new ImaginaryPoint(20,35);

     // now l2.arr is [nullptr, nullptr, nullptr]
    l2.addElement(i1);
    // now l2.arr is [i1, nullptr, nullptr]
    l2.addElement(i2);
    // now l2.arr is [i1, i2, nullptr]
    l2.addElement(i3);
    // now l2.arr is [i3, i1, i2]
    l2.addElement(i4);
    // now l2.arr is [i3, i4, i1]
    l2.addElement(i5);
    // now l2.arr is [i3, i4, i1]

    ImaginaryPoint* l2_zero = l2.getBottomXthElement(0);
    ImaginaryPoint* l2_one = l2.getBottomXthElement(1);

    cout<<(l2_zero->get_real_part())<<endl;
    cout<<(l2_zero->get_imaginary_part())<<endl;
    cout<<(l2_one->get_real_part())<<endl;
    cout<<(l2_one->get_imaginary_part())<<endl;

    return 0;
}
