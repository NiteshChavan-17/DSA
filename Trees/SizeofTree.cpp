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

    int SizeofTree(Node*root, int &count) {
        if(root==NULL) {
            return 0;
        }

        count++;
        SizeofTree(root->left,count);
        SizeofTree(root->right, count);

        return count;
    }
};


int main() {

    Tree t1;
    cout<<"Enter the root node:";
    Node*root = t1.BinaryTree();

    cout<<"Preorder Traversal: ";
    t1.Preorder(root);

    int count = 0;
    int treeSize = t1.SizeofTree(root,count);

    cout<<"Size of tree:"<<treeSize<<endl;

    return 0;
}