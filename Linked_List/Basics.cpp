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
        }
        
        newNode->next = head;
        head = newNode;
    }

    void push_back(int val) {
        Node*newNode = new Node(val);

        if(head==NULL) {
            head = tail = newNode;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void InsertatPos(int val, int pos) {
        Node*newNode = new Node(val);
        Node*temp = head;

        if(pos<0) {
            cout<<"Invalid pos";
            return;
        }
        else if(pos==0) {
            push_front(val);
        }
        else {
            for(int i=0;i<pos-1;i++) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void Delete_Front() {
        if(head==NULL) {
            cout<<"List is Empty"<<endl;
            return;
        }

        Node*temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void Delete_End() {
        if(head==NULL) {
            cout<<"List is Empty"<<endl;
            return;
        }

        Node*temp = head;
        while(temp->next!=tail) {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
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

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(6);
    ll.InsertatPos(7,0);
    

    cout<<"Linked List:"<<endl;
    ll.print();

    return 0;
}