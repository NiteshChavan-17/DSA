#include<iostream>
#include<queue>
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

    void LevelOrder(Node*root) {
        queue<Node*>q;
        q.push(root);

        while(!q.empty()) {
            Node*temp = q.front();
            q.pop();
            cout<<temp->data<<" ";

            if(temp->left) {
                q.push(temp->left);
            }

            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
};


int main() {

    Tree t1;
    cout<<"Enter the root node:";
    Node*root = t1.BinaryTree();

    cout<<"Level Order Traversal:";
    t1.LevelOrder(root);

    return 0;
}