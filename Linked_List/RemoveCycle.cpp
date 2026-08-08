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

    Node*RemoveCycle() {
        Node*fast = head;
        Node*slow = head;
        bool isCycle = false;

        while(fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast) {
                isCycle = true;
                break;
            }
        }

        if(!isCycle) {
            return NULL;
        }

        Node*prev = NULL;
        slow = head;

        while(slow!=fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }

        prev->next = NULL;
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

    Node*removeCycle = ll.RemoveCycle();
    cout<<"List after removing cycle:"<<removeCycle->data<<endl;
    

    return 0;
}