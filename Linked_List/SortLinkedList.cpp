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

    Node*gethead() {
        return head;
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

    Node*MergeSortedList(Node*h1, Node*h2) {

        if(h1==NULL || h2==NULL) {
            return h1==NULL? h2:h1;
        }

        if(h1->data<=h2->data) {
            h1->next = MergeSortedList(h1->next, h2);
            return h1;
        }
        else{
            h2->next = MergeSortedList(h1,h2->next);
            return h2;
        }
    }

    Node*SortList(Node*head) {

        if(head==NULL || head->next==NULL) {
            return head;
        }
        
        Node*slow = head;
        Node*fast = head;
        Node*prev = NULL;

        while(fast!=NULL && fast->next!=NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;

        Node*h1 = SortList(head);
        Node*h2 = SortList(slow);

        return MergeSortedList(h1,h2);
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

    
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(4);
    

    cout<<"Linked List:"<<endl;
    ll.print();

    Node*newHead = ll.SortList(ll.gethead());
    cout<<"\nList after sorting:"<<endl;
    
    Node*temp = newHead;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    return 0;
}