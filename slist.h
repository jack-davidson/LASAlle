#include <iostream>

struct node {
    node *next;
    void *data;
};

class LinkedList {
private:
    node *head; // head pointer
    int length;

public:
    // Constructor
    LinkedList();
    // Destructor
    ~LinkedList();

    // add(value)				//Adds a new value to the end of this list.
    void add(void *a);

    // clear()					//Removes all elements from this list.
    void clear();

    // equals(list)				//Returns true if the two lists contain the same elements in the same order.
    bool operator==(LinkedList *rhs);

    //get(index)				//Returns the element at the specified index in this list.
    node *get(int index);
    void *operator[](int index);

    //insert(index, value)		//Inserts the element into this list before the specified index.
    void insert(int index);

    //exchg(index1, index2)		//Switches the payload data of specified indexex.
    void exchg(int i1, int i2);

    //swap(index1,index2)		//Swaps node located at index1 with node at index2
    void swap(int i1, int i2);

    // isEmpty()				//Returns true if this list contains no elements.
    bool isEmpty();

    // remove(index)			//Removes the element at the specified index from this list.
    void remove(int i);

    // set(index, value)		//Replaces the element at the specified index in this list with a new value.
    void set(int i, void *a);

    // size()					//Returns the number of elements in this list.
    int size();

    // subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
    LinkedList subList(int start, int length);

    // toString()				//Converts the list to a printable string representation.
    std::string toString();
};