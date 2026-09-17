#include<iostream>
using namespace std;

class Node {
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

class Tree {
    public:
    Node*root;
    Node*NextRight;

    public:
    Tree() {
        root = NULL;
        NextRight = NULL;
    }

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

    void FlattenTree(Node*root) {
        if(root==NULL) {
            return;
        }
        FlattenTree(root->right);
        FlattenTree(root->left);
        root->left = NULL;
        root->right = NextRight;
        NextRight = root;
    }
    
};

int main() {

    Tree t1;

    cout<<"Enter the root Node:";
    Node*root = t1.BinaryTree();

    t1.FlattenTree(root);

    Node*flatten = root;

    while(flatten!=NULL) {
        cout<<flatten->data<<" ";
        flatten = flatten->right;
    }

    return 0;
}