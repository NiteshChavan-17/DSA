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

    Node*DeleteNthNode(int n) {

        int count = 0;
        Node*temp = head;
        while(temp!=NULL) {
            count++;
            temp = temp->next;
        }

        count-=n;

        if(count==0) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        
        Node*curr = head;
        Node*prev = NULL;
        while(count--) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;

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

    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    

    cout<<"Linked List:"<<endl;
    ll.print();


    int n;
    cout<<"Enter the node to delete from end:";
    cin>>n;

    ll.DeleteNthNode(n);
    cout<<"List After Deletion:"<<endl;
    ll.print();

    return 0;
}