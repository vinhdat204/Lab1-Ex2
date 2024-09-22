// STT: 22520228
// Full Name: Nguyen Vinh Dat
// Lab 1: In-Class exercise 2

#include <iostream>
#include <vector> 
#include "Node.h"
using namespace std;

vector<Node*> splitToParts(Node* head, int k) {
    vector<Node*> res(k);
    int cnt = 0;
    Node *ptr = head;
    while(ptr) {
        ptr = ptr->next;
        cnt++;
    }
    int div = cnt / k;
    int mod = cnt % k;

    if(div == 0) {
        div = 1;
        mod = 0;
    }

    ptr = head;
    int i = 0;
    while(ptr != NULL) {
        res[i++] = ptr;
        int step;

        if(mod > 0) {
            step = div + 1;
            mod--;
        } else {
            step = div;
        }
        
        while(step) {
            if(step == 1) {
                Node *tmp = ptr;
                ptr = ptr->next;
                tmp->next = NULL;
            } else {
                ptr = ptr->next;
            }
            step--;
        }
    }

    return res;
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

    int n = 3;
    vector<Node*> v = splitToParts(head, n);
    cout << "Split linked list to " << n << " list:" << endl;
    for(Node* &n : v) {
        while(n) {
            cout << n->data << " ";
            n = n->next;
        }
        cout << endl;
    }

    return 0;
}



