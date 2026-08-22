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

    void Preorder(Node*root) {
        if(root==NULL) {
            return;
        }

        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }

    bool IdenticalTrees(Node*r1, Node*r2) {
        if(r1==NULL && r2==NULL) {
            return true;
        }

        if((r1==NULL && r2!=NULL) || (r1!=NULL && r2==NULL)) {
            return false;
        }

        if(r1->data!=r2->data) {
            return false;
        }

        return (IdenticalTrees(r1->left,r2->left) && IdenticalTrees(r1->right,r2->right));
    }
};


int main() {

    Tree t1;
    cout<<"Enter the root 1 node:";
    Node*root1 = t1.BinaryTree();

    cout<<"Enter the root 2 node:";
    Node*root2 = t1.BinaryTree();

    cout<<"Preorder Traversal: ";
    t1.Preorder(root1);

    cout<<endl;
    t1.Preorder(root2);

    cout<<endl;

    bool identical = t1.IdenticalTrees(root1,root2);

    if(identical) {
        cout<<"Trees are Identical"<<endl;
    }
    else {
        cout<<"Trees are not identical"<<endl;
    }

    return 0;
}