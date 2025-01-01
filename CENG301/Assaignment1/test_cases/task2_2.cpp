#include <iostream>
using namespace std;

#include "BottomKList.h"

int main() {
    BottomKList<int,2> l1;
    int *a = new int(1),
        *b = new int(0),
        *c = new int(-2),
        *d = new int(-3),
        *e = new int(-7),
        *f = new int(-1);
    l1.addElement(a);
    // now l1.arr is [a, nullptr]
    l1.addElement(b);
    // now l1.arr is [b, a]

    int* l1_zero = l1.getBottomXthElement(0);
    int* l1_one = l1.getBottomXthElement(1);

    cout<<(*l1_zero)<<endl;
    cout<<(*l1_one)<<endl;

    l1.addElement(c);
    // now l1.arr is [c, b]

    l1_zero = l1.getBottomXthElement(0);
    l1_one = l1.getBottomXthElement(1);

    cout<<(*l1_zero)<<endl;
    cout<<(*l1_one)<<endl;

    l1.addElement(d);
    // now l1.arr is [d, c]

    l1_zero = l1.getBottomXthElement(0);
    l1_one = l1.getBottomXthElement(1);

    cout<<(*l1_zero)<<endl;
    cout<<(*l1_one)<<endl;

    l1.addElement(e);
    // now l1.arr is [e, d]

    l1_zero = l1.getBottomXthElement(0);
    l1_one = l1.getBottomXthElement(1);

    cout<<(*l1_zero)<<endl;
    cout<<(*l1_one)<<endl;

    l1.addElement(f);
    // now l1.arr is [e, d]

    l1_zero = l1.getBottomXthElement(0);
    l1_one = l1.getBottomXthElement(1);

    cout<<(*l1_zero)<<endl;
    cout<<(*l1_one)<<endl;

    BottomKList<int,2> l2;
    int *aa = new int(-1),
        *bb = new int(1);
    l2.addElement(aa);
    // now l2.arr is [a]
    l2.addElement(bb);
    // now l2.arr is [a]

    int* l2_zero = l2.getBottomXthElement(0);
    int* l2_one = l2.getBottomXthElement(1);

    cout<<(*l2_zero)<<endl;
    cout<<(*l2_one)<<endl;

    return 0;
}
