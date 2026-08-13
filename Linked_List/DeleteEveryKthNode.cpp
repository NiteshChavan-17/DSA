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

    Node*DeleteKthNode(int k) {

        Node*prev = NULL;
        Node*curr = head;

        if(k<=0) {
            return head;
        }

        int count = 1;
        while(curr!=NULL) {
            if(count==k) {
                if(prev==NULL) {
                    head = curr->next;
                    delete curr;
                    curr = head;
                }
                else {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                    count = 1;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
                count++;
            }
        }

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
    cout<<"\nEnter the kth node to delete:";
    cin>>k;

    ll.DeleteKthNode(k);
    cout<<"List After Deletion:"<<endl;
    ll.print();

    return 0;
}