// STT: 22520228
// Full Name: Nguyen Vinh Dat
// Lab 1: In-Class exercise 2

#include <iostream>
#include "Node.h"
using namespace std;

void swapNode(Node *head, int k) {
    Node *ptr = head;
    int len = 0;
    while(ptr) {
        len++;
        ptr = ptr->next;
    }

    ptr = head;
    int i = 0;
    for(; i < k - 1; i++) {
        ptr = ptr->next;
    }
    Node *p1 = ptr;

    ptr = head;
    i   = 0;
    for(; i < len - k; i++) {
        ptr = ptr->next;
    }
    Node *p2 = ptr;

    int tmp = p1->data;
    p1->data = p2->data;
    p2->data = tmp;
}

int main() {
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);

    Node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    Node *ptr = head;
    cout << "List: ";
    while(ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;

    swapNode(head, 1);

    ptr = head;
    cout << "After Swap: ";
    while(ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;

    return 0;
}