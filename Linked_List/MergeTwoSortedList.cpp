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

    Node*getHead() {
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

    void print() {
        Node*temp = head;

        while(temp!=NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main() {

    LL list1;
    LL list2;

    list1.push_front(5);
    list1.push_front(3);
    list1.push_front(1);

    list2.push_front(6);
    list2.push_front(4);
    list2.push_front(2);

    cout << "List 1: ";
    list1.print();

    cout << "\nList 2: ";
    list2.print();

    Node* mergedHead = list1.MergeSortedList(list1.getHead(), list2.getHead());

    cout << "\nMerged List: ";

    Node* temp = mergedHead;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}