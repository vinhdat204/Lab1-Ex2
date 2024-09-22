// STT: 22520228
// Full Name: Nguyen Vinh Dat
// Lab 1: In-Class exercise 2

#include <iostream>
#include "Node.h"
using namespace std;

void removeZeroSum(Node* head) {
    Node* n = new Node(0);
    n->next = head;

    Node* p1 = n;
    while(p1) {
        Node* p2 = p1->next;
        int sum = 0;
        while(p2) {
            sum += p2->data;
            if(sum == 0) {
                Node* p = p1->next;
                p1->next = p2->next;
                while(p != p2) {
                    Node* delNode = p;
                    p = p->next;
                    delete delNode;
                }
                p2 = p2->next;
                delete p;
                continue;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    Node* ptr = n->next;
    cout << "Linked list after removing zero sum: ";
    while(ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
    
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(-3);
    Node* n5 = new Node(1);
    Node* n6 = new Node(2);

    Node* head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    Node* ptr = head;
    while(ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;

    
    removeZeroSum(head);

}