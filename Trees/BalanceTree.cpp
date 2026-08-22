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

class Tree{

    public:
    Node*root;

    Tree() {
        root = NULL;
    }

    Node*BinaryTree() {
        int x;
        cin>>x;

        if(x==-1) {
            return NULL;
        }

        Node*temp = new Node(x);

        cout<<"Enter left child of "<<x<<":";
        temp->left = BinaryTree();
        cout<<"Enter the right child of "<<x<<":";
        temp->right = BinaryTree();

        return temp;
    }

    void Inorder(Node*root) {
        if(root==NULL) {
            return;
        }

        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }

    int height(Node*root) {
        if(root==NULL) {
            return 0;
        }

        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalance(Node*root) {

        if(root==NULL) {
            return true;
        }
        int balance = height(root->left) - height(root->right);

        if(abs(balance)>1) {
            return false;
        }

        return isBalance(root->left) && isBalance(root->right);
    }
};


int main() {

    Tree t1;
    cout<<"Enter the root node:";
    Node*root = t1.BinaryTree();

    cout<<"Inorder Traversal: ";
    t1.Inorder(root);

    cout<<endl;

    bool balancetree = t1.isBalance(root);

    if(balancetree) {
        cout<<"Tree is balanced"<<endl;
    }
    else {
        cout<<"Tree is not balanced"<<endl;
    }

    return 0;
}