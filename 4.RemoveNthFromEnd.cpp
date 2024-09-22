// STT: 22520228
// Full Name: Nguyen Vinh Dat
// Lab 1: In-Class exercise 2

#include <iostream>
#include "Node.h"
using namespace std;

void helper(Node *&head, Node *current, Node *prev, int &n) {
    if(current == nullptr) {
        return;
    }
    helper(head, current->next, current, n);
    n--;
    if(n == 0) {
        if(prev != nullptr)
            prev->next = current->next;
        else 
            head = current->next;

        delete current;  
        n--;  
    }
}

Node* removeNthFromEnd(Node* head, int n) {
    helper(head, head, nullptr, n);
    return head;
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

    int n = 4;
    head = removeNthFromEnd(head, n);

    ptr = head;
    cout << "After remove Nth Node"  << "(N = " << n << ") " <<"from end: ";
    while(ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;

    return 0;
}