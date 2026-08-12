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

    Node* RotateList(int k) {

        if(head == NULL || head->next == NULL) {
            return head;
        }

    
        int count = 0;
        Node* temp = head;

        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

    
        k = k % count;

        if(k == 0) {
            return head;
        }

        count-=k;

        Node* prev = NULL;
        Node* curr = head;

        while(count--) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
    
        Node* tail = curr;

        while(tail->next != NULL) {
            tail = tail->next;
        }

        tail->next = head;
        head = curr;

        return head;
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

    ll.push_front(9);
    ll.push_front(8);
    ll.push_front(7);
    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    

    cout<<"Linked List:"<<endl;
    ll.print();


    int k;
    cout<<"\nEnter the kth node to Rotate:";
    cin>>k;

    ll.RotateList(k);
    cout<<"List After after rotation:"<<endl;
    ll.print();

    return 0;
}