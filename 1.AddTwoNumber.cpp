// STT: 22520228
// Full Name: Nguyen Vinh Dat
// Lab 1: In-Class exercise 2


#include <iostream>
#include <cmath>
#include "Node.h"
using namespace std;



Node* AddTwoNumber(Node *h1, Node *h2) {
    Node *head = nullptr;
    Node *tail = nullptr;

    int r = 0;
    while(h1 != nullptr || h2 != nullptr) {
        r += h1->data + h2->data;
        Node *newNode = new Node(r % 10);
        r /= 10;
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        h1 = h1->next;
        h2 = h2->next;
    }

    while(h1 != nullptr) {
        r += h1->data;
        Node *newNode = new Node(r % 10);
        r /= 10;
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        h1 = h1->next;
    }

    while(h2 != nullptr) {
        r += h2->data;
        Node *newNode = new Node(r % 10);
        r /= 10;
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        h2 = h2->next;

        if(r != 0) {
            tail->next = new Node(r);
        }
    }

    return head;
}

int main() {
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);

    Node *h1 = n1;
    n1->next = n2;
    n2->next = n3;

    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);

    Node *h2 = n4;
    n4->next = n5;
    n5->next = n6;

    Node *ptr = h1;
    cout << "List 1: ";
    while(ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;

    ptr = h2;
    cout << "List 2: ";
    while(ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;

    Node *head = AddTwoNumber(h1, h2);
    cout << "Add two number: ";
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;


    return 0;
}