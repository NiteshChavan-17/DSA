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

class BST {
    public:
    Node*root;

    BST() {
        root = NULL;
    }

    Node*insert(Node*root, int val) {
        if(root==NULL) {
            return new Node(val);
        }

        else if(val<root->data) {
            root->left = insert(root->left,val);
        }

        else{
            root->right = insert(root->right,val);
        }

        return root;
    }

    bool search(Node*root, int val) {
        if(root==NULL) {
            cout<<"\nValue Not found"<<endl;
            return false;
        }

        if(root->data==val) {
            cout<<"Value Found:"<<root->data<<endl;
            return true;
        }
        if(val<root->data) {
            return search(root->left,val);
        }
        else{
            return search(root->right,val);
        }
    }

    Node*getInorderSuccessor(Node*root) {
        Node*temp = root->right;
        while(temp->left!=NULL) {
            temp = temp->left;
        }

        return temp;
    }

    Node*DeleteNode(Node*root, int key) {

        if(root==NULL) {
            return NULL;
        }

        if(key<root->data) {
            root->left = DeleteNode(root->left,key);
        }

        else if(key>root->data) {
            root->right = DeleteNode(root->right,key);
        }

        else{
            if(root->left==NULL) {
                Node*temp = root->right;
                delete root;
                return temp;
            }

            else if(root->right==NULL) {
                Node*temp = root->left;
                delete root;
                return temp;
            }

            else{
                Node*successor = getInorderSuccessor(root);
                root->data = successor->data;
                root->right = DeleteNode(root->right,successor->data);
            }
        }

        return root;
    }

    void Inorder(Node*root) {
        if(root==NULL) {
            return;
        }

        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
};

int main() {

    
    BST t1;

    t1.root = t1.insert(t1.root,3);
    t1.root = t1.insert(t1.root,2);
    t1.root = t1.insert(t1.root,1);
    t1.root = t1.insert(t1.root,5);
    t1.root = t1.insert(t1.root,6);
    t1.root = t1.insert(t1.root,4);

    t1.Inorder(t1.root);

    t1.search(t1.root,7);

    t1.root = t1.DeleteNode(t1.root,5);

    cout<<"Tree after deletion:"<<endl;
    t1.Inorder(t1.root);

    return 0;
}