#include <iostream>
#include <string>


struct Person{

    std::string name {};
    int age;

    void kisses(const Person& person){
        std::cout << name << " kisses " << person.name <<"\n";
    }
};

int main()
{

    Person joe{"joe", 29};

    Person kate{"kate", 27};

    joe.kisses(kate);


    return 0;
}
