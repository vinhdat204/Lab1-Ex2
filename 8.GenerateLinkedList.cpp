// STT: 22520228
// Full Name: Nguyen Vinh Dat
// Lab 1: In-Class exercise 2

#include <iostream>
#include "Node.h"
using namespace std;

struct List {
    Node* head;
    Node* tail;
    List() {
        this->head = nullptr;
        this->tail = nullptr;
    }
};

void addTail(List &l, Node* node) {
    if(l.head == nullptr) {
        l.head = node;
        l.tail = node;
    } else {
        l.tail->next = node;
        l.tail = node;
    }
}

void generateList() {
    srand(time(0));
    List l;
    int entries = (rand() % (59 - 39 + 1) ) + 39;
    for(int i = 1; i <= entries; i++) {
        addTail(l, new Node((rand() % (99 + 99 + 1) - 99)));
    }

    Node* ptr = l.head;
    cout << "The list has " << entries << " entries: ";
    while(ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    generateList();
    return 0;
}