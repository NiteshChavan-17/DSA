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

    void DeleteNthNode(int n) {
        Node*slow = head;
        Node*fast = head;

        for(int i=0;i<n;i++) {
            fast = fast->next;
        }

        if(fast==NULL) {
            head = head->next;
            delete slow;
            return;
        }

        while(fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
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

    int n;
    cout<<"\nEnter the node to delete from end:";
    cin>>n;

    ll.DeleteNthNode(n);

    cout<<"\nList after deletion:"<<endl;
    ll.print();

    return 0;
}