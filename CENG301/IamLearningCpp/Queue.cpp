#include <iostream>

using namespace std;

class QueueNode{
public:
    int item;
    QueueNode* next;
};

class Queue{
private:

    QueueNode* backPtr;
    QueueNode* frontPtr;

public:
    void enqueue(int newItem);
    int dequeue();
    int getFrontItem();
    int size();
    QueueNode* getFrontPtr();
    void printQueue();
    friend class QueueNode;
};

void Queue::enqueue(int newItem){
    QueueNode* newPtr = new QueueNode;
    newPtr->item = newItem;
    newPtr->next = NULL;

    if(backPtr==NULL){ //isEmpty()
        frontPtr = newPtr;
    } else{
        backPtr->next = newPtr;
    }
    backPtr = newPtr;
}

int Queue::dequeue(){
    QueueNode *tempPtr = frontPtr; //creating a temp ptr
    frontPtr = frontPtr->next; //moving frontPtr to the next element

    //tempPtr->item = NULL;   //delete the node's item part
    delete tempPtr; // delete the temp pointer pointing the node will be deleted
    return frontPtr->item;
}

int Queue::getFrontItem(){
    return frontPtr->item;
}


int Queue::size(){
    int size = 0;
    QueueNode* p = frontPtr;

    while(p){
        size++;
        p = p->next;
    }
    return size;
}

QueueNode* Queue::getFrontPtr(){
    return frontPtr;
}

void Queue::printQueue(){
    
    //cout << frontPtr->item;
    QueueNode *currentPtr = frontPtr; //create a current pointer to point all items respectfully and prints them

    while(currentPtr!= nullptr){

        if(currentPtr->next == nullptr){
            cout << currentPtr->item;
            break;
        }
        cout << currentPtr->item << "-> "; //printing
        currentPtr = currentPtr->next;  //switching to the next node
    }
}

void swapFirtsK(Queue q, int k){ //q is referring to the queue
    if(q.size() <k){cout << "\nk is bigger than the size of queue.";}

    int evenK = (k % 2==0 ? k : k-1);

    for(int i=0; i< evenK/2; i++){ //this loop is for re-ordering
        int elem1 = q.dequeue();
        int elem2 = q.dequeue();
        q.enqueue(elem2);
        q.enqueue(elem1);

    }
            
    for (int i = 0; i < q.size() -evenK; i++) //this is for moving everything -except the moved elements from that moved- to the end of the list.
    {
        q.enqueue( q.dequeue());
    }
        


}



int main(){

    Queue myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.enqueue(6);

    myQueue.printQueue();
    swapFirtsK(myQueue, 5);



    cout<<"\nFinal queue:\n"<<endl;

    myQueue.printQueue();


    return 0;
}