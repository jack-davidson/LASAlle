#include "slist.h"
#include <iostream>

/*
Class Library File

Author: Jack Davidson
*/
#define f  std::cout << "fail" << std::endl;

// Constructor
LinkedList::LinkedList() {
    length = 0;
    head = NULL;
}

// Destructor
LinkedList::~LinkedList() {
    /*
    node *m, *n;
    n = head;
    while (n) {
        m = n;
        free(m);
        n = n->next;
    }
    */
}

// add(value)				//Adds a new value to the end of this list.
void LinkedList::add(void *data) {
    node *p = (node *)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    
    if (head == NULL) { // no head yet
        head = p;
        return;
    }
    
    node *i;
    for (i = head; i->next; i=i->next) {}
    i->next = p;
    length++;
}

// clear()					//Removes all elements from this list.
void LinkedList::clear() {
    
}

// equals(list)				//Returns true if the two lists contain the same elements in the same order.
bool LinkedList::operator==(LinkedList *rhs) {
    return false;
}

//get(index)				//Returns the element at the specified index in this list.
node *LinkedList::get(int index) {
    int c;
    node *i;
    
    i = head;
    for (c = 0; c < index; c++) {
        i = i->next;
    }
    return i;
}

void *LinkedList::operator[](int index) {
    int c;
    node *i;
    
    i = head;
    for (c = 0; c < index; c++) {
        i = i->next;
    }
    return i->data;
}

//insert(index, value)		//Inserts the element into this list before the specified index.
void LinkedList::insert(int index) {
    
}

//exchg(index1, index2)		//Switches the payload data of specified indexex.
void LinkedList::exchg(int i1, int i2) {
    
}

//swap(index1,index2)		//Swaps node located at index1 with node at index2
void LinkedList::swap(int i1, int i2) {
    node *n1 = get(i1);
    node *n2 = get(i2);

    void *tmp = n1->data;
    n1->data = n2->data;
    n2->data = tmp;
}

// isEmpty()				//Returns true if this list contains no elements.
bool LinkedList::isEmpty() {
    return false;
}

// remove(index)			//Removes the element at the specified index from this list.
void LinkedList::remove(int i) {
    
}

// set(index, value)		//Replaces the element at the specified index in this list with a new value.
void LinkedList::set(int i, void *a) {
    
}

// size()					//Returns the number of elements in this list.
int LinkedList::size() {
    return length;
}

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
LinkedList LinkedList::subList(int start, int length) {
    return LinkedList();
}

// toString()				//Converts the list to a printable string representation.
std::string LinkedList::toString() {
    return "";
}