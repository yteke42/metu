#include "LinkedList.h"
#include "myUsers.h"

int main() {
    LinkedList list;
    myUsers user1(1, "User1");
    myUsers user2(2, "User2");

    list.insert(&user1);
    list.insert(&user2);

    list.print();

    return 0;
}
