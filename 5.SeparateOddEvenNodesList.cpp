// STT: 22520228
// Full Name: Nguyen Vinh Dat
// Lab 1: In-Class exercise 2

#include <iostream>
#include "Node.h"
using namespace std;

void SeparateOddEvenNodeList(Node* head) {
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while(even != nullptr && even->next != nullptr) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
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

    cout << "Original linked list: ";
    Node* ptr = head;
    while(ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;

    SeparateOddEvenNodeList(head);
    cout << "After separating odd and even nodes in linked list: ";
    ptr = head;
    while(ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;

    return 0;
}