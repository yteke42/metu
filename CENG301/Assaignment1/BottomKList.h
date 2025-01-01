#ifndef BOTTOMKLIST_H
#define BOTTOMKLIST_H
template<typename T, int k>
class BottomKList {
private:
    T* arr[k];
public:
    BottomKList()
    {
        // MODIFY HERE: Implement the constructor.
        for(int i=0; i<k; i++){
            arr[i] = nullptr;
        }
        
    }
    ~BottomKList()
    {
        // MODIFY HERE: Implement the destructor (if needed).
        for(int i=0; i<k; i++) {
            delete arr[i];
        }

    }

    void addElement( T* element )
    {
        // MODIFY HERE: Implement the addElement function.
        //fiinding where to put the element

        int index = k-1;
        while (index >=0 && (arr[index] == nullptr || !(*arr[index] < *element))) {
            --index;
        }

        //shifting elements to right to insert the new one
        for (int j=k-1; j>index; --j) {
            arr[j] = arr[j-1];
        } 

        //finally, inserting
        arr[index+1] = element;

    }
    T* getBottomXthElement ( int x ) const  
    {
        // MODIFY HERE: Implement the getBottomXthElement function.
        // do not forget to return nullptr if x >= k or x < 0
        if(x <0 || x>=k) {
            return nullptr;
        }
        return arr[x];
    }
};
#endif