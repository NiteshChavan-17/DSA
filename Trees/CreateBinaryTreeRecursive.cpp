#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node*BinaryTree() {
    int x;
    cin>>x;

    if(x==-1) {
        return NULL;
    }
    
    Node*temp = new Node(x);
    cout<<"Enter the left child of "<<x<<":";
    temp->left = BinaryTree();
    cout<<"Enter the right child of "<<x<<":";
    temp->right = BinaryTree();
    return temp;
}

int main() {

    cout<<"Enter the root Node:";
    Node*root = BinaryTree();
    return 0;
}