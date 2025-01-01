#include <iostream>
using namespace std;

template <class ListItemType>
class Node {
public:
    Node(const ListItemType& e = ListItemType(), Node* n = NULL) : element(e), next(n) {};

    ListItemType element;
    Node* next;
};

template <class ListItemType>
class List {
private:
    Node<ListItemType>* dummyHead;

public:
    // Constructor
    List();

    // Destructor
    ~List();

    // Copy constructor
    List(const List& rhs);

    // Assignment operator
    List& operator=(const List& rhs);

    // Function to return the pointer to the zeroth node
    Node<ListItemType>* zeroth() const;

    // Function to return the pointer to the first node
    Node<ListItemType>* first() const;

    // Function to check if the list is empty
    bool isEmpty() const;

    // Function to insert a new node with data after node p
    void insert(const ListItemType& data, Node<ListItemType>* p);

    // Function to find a node with data in the list
    Node<ListItemType>* find(const ListItemType& data) const;

    // Function to find the node before the node with data in the list
    Node<ListItemType>* findPrevious(const ListItemType& data) const;

    // Function to remove a node with data from the list
    void remove(const ListItemType& data);

    void removeByOnlyAccessingThatNode(const ListItemType& data);

    // Function to make the list empty
    void makeEmpty();

    void print() const;

    void replicateItem(const ListItemType& data);

    void update();

    void findMax();
};

template <class ListItemType>
List<ListItemType>::List() {
        // Initialize dummyHead with default element and NULL next pointer
        dummyHead = new Node<ListItemType>(ListItemType(), NULL);
}

template <class ListItemType>
List<ListItemType>::~List(){
    makeEmpty();
    delete dummyHead;
}

template <class ListItemType>
bool List<ListItemType>::isEmpty() const {
    return (dummyHead->next) == NULL;
}

template <class ListItemType>
Node<ListItemType>* List<ListItemType>::zeroth() const {
    return dummyHead;
}

template <class ListItemType>
Node<ListItemType>* List<ListItemType>::first() const {
    return dummyHead->next;
}

template <class ListItemType>
void List<ListItemType>::insert(const ListItemType& data, Node<ListItemType>* p) {
    if (p == NULL) {
        // Insert at the beginning of the list
        Node<ListItemType>* newNode = new Node<ListItemType>(data, dummyHead->next);
        dummyHead->next = newNode; // Update dummyHead's next pointer
    } else {
        // Insert after node p
        Node<ListItemType>* newNode = new Node<ListItemType>(data, p->next);
        p->next = newNode; // Update p's next pointer
    }   
}

template <class ListItemType>
Node<ListItemType> *List<ListItemType>::find(const ListItemType &data) const{

    Node<ListItemType> *p =first(); //creating a pointer to point through the whole list to find the element

    while(p){ //while(p!=NULL),  also means p exists through the list 
        if(p->element == data){
            return p;
        }
        p = p->next;
    }
    return NULL;
}


template<class ListItemType> 
Node<ListItemType> *List<ListItemType>::findPrevious(const ListItemType &data) const{
    Node<ListItemType> *p = zeroth();

    while (p->next){ //we used p->next because we want the next element to be equal to data, then we can return the preivous.
        if(p->next->element == data){
            return p;
        }
        p = p->next;
    }
    return NULL;
}



template <class ListItemType>
void List<ListItemType>::remove(const ListItemType& data){
    Node<ListItemType>* p = findPrevious(data);

    if(p){ //or p!=NULL
        Node<ListItemType> *temp = p->next;
        p->next = temp->next; //"p->next" is now "p->next->next" , so we removed the element in the middle 
        delete temp; //delete the unnecesarry pointer
    }

}


template <class ListItemType>
void List<ListItemType>::removeByOnlyAccessingThatNode(const ListItemType& data){
    Node<ListItemType>* p = find(data);

    if (p){
        p->element =p->next; //copy the next element backwards
        Node<ListItemType> *temp = p->next;  //then delete the next one
        p->next = temp->next;
        delete temp;
    }
    

}

template <class ListItemType>
void List<ListItemType>::print() const {
    const Node<ListItemType> *p = first();

    while(p){
        cout << p->element << " -> " ;
        p = p->next;
    }

}

template <class ListItemType>
void List<ListItemType>::makeEmpty(){

    while (!isEmpty()){ //it works untill the list is fully empty
        remove(first()->element); 
    }
    
}

/* template <class ListItemType>
void List<ListItemType>::replicateItem(const ListItemType& data){

    List<ListItemType>* p = first();

    while(p){
        if(p->element == data){
            p->next = new List<ListItemType>(data,p->next);
            p = p->next;
        }
        p = p->next;
    }



} */

template <class ListItemType>

void List<ListItemType>::findMax(){
    Node<ListItemType> *p = first(); //make a pointer

    ListItemType max= -1; //initialize a max variable

    while(p){ //find the max,  max is the element, last is the pointer to max
        if(p->element > max){
            max = p->element;
        }
        p = p->next;
    }
    cout<<max;
}



template <class ListItemType>
void List<ListItemType>::update(){
    if(isEmpty()){
    return;
    }

    Node<ListItemType> *p = first(); //make a pointer
    Node<ListItemType> *last = NULL;

    ListItemType max= -1; //initialize a max variable

    while(p){ //find the max,  max is the element, last is the pointer to max
        if(p->element > max){
            max = p->element;
        }
        last = p;
        p = p->next;
    }


    remove(max);

    if(int(max) % 2 ==0){
        insert(max,last);
    }else{
        insert(max, zeroth());
    }
}




int main() {

    List<int> myList;

    myList.insert(10, NULL);  
    myList.insert(90, myList.first());  
    myList.insert(30, myList.first()->next);  
    myList.insert(4, myList.first()->next->next);  
    myList.insert(50, myList.first()->next->next->next);  
    myList.insert(12, myList.first()->next->next->next->next);  



    
    myList.print();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    myList.update();
    myList.print();


    return 0;
}
