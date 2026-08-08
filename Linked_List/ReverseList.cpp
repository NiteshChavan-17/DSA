#include<iostream>
using namespace std;

class Node {
    public:

    int data;
    Node*next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class LL {
    Node*head;
    Node*tail;

    public:
    LL() {
        head = tail = NULL;
    }

    void push_front(int val) {

        Node*newNode = new Node(val);
        if(head==NULL) {
            head = tail = newNode;
            return;
        }
        
        newNode->next = head;
        head = newNode;
    }

    void Reverse() {

        Node* prev = NULL;
        Node* curr = head;

        tail = head;

        while(curr != NULL) {

            Node* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
    }

    void print() {
        Node*temp = head;

        while(temp!=NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main() {

    LL ll;

    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    

    cout<<"Linked List:"<<endl;
    ll.print();

    ll.Reverse();

    cout<<"\nReverse List:"<<endl;

    ll.print();

    return 0;
}