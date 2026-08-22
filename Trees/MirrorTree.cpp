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

    void MirrorTree(Node*root) {
        if(root==NULL) {
            return;
        }

        Node*temp = root->right;
        root->right = root->left;
        root->left = temp;

        MirrorTree(root->left);
        MirrorTree(root->right);
    }
};


int main() {

    Tree t1;
    cout<<"Enter the root node:";
    Node*root = t1.BinaryTree();

    cout<<"Inorder Traversal: ";
    t1.Inorder(root);

    cout<<endl;

    t1.MirrorTree(root);

    cout<<"Inorder Traversal after mirror image: ";
    t1.Inorder(root);

    return 0;
}