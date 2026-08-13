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

    bool PalindromeList() {

        Node*fast = head;
        Node*slow = head;

        while(fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node*curr = slow->next;
        slow->next = NULL;

        Node*prev = NULL;
        Node*front = NULL;

        while(curr!=NULL) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        Node*head1 = head;
        Node*head2 = prev;

        while(head1!=NULL && head2!=NULL) {
            if(head1->data!=head2->data) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
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

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    

    cout<<"Linked List:"<<endl;
    ll.print();

    bool palindrome = ll.PalindromeList();

    if(palindrome) {
        cout<<"\nList is Palindrome"<<endl;
    }
    else{
        cout<<"\nList is not Palindrome"<<endl;
    }

    return 0;
}