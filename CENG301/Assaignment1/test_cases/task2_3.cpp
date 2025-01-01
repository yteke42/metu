#include <iostream>
using namespace std;

#include "BottomKList.h"
#include "ImaginaryPoint.h"

int main() {
    BottomKList<int,5> l1;
    int num = 0;
    for(int i = 0;i<5;i++)
    {
        for(int j = 0;j<5;j++)
        {
            int *a = new int(j*5+i);
            l1.addElement(a);
            //cout<<(*a)<<" added"<<endl;
            //num++;

            //for(int k = 0;k< min(num,5);k++)
            //{
            //    cout<<(*(l1.getBottomXthElement(k)))<<endl;
            //}
            //cout<<endl;
        }
    }

    int* l1_zero = l1.getBottomXthElement(0);
    int* l1_one = l1.getBottomXthElement(1);
    int* l1_two = l1.getBottomXthElement(2);
    int* l1_three = l1.getBottomXthElement(3);
    int* l1_four = l1.getBottomXthElement(4);

    cout<<(*l1_zero)<<endl;
    cout<<(*l1_one)<<endl;
    cout<<(*l1_two)<<endl;
    cout<<(*l1_three)<<endl;
    cout<<(*l1_four)<<endl;


    return 0;
}
