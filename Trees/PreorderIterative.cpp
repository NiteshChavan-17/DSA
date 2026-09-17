#include<iostream>
#include<stack>
#include<vector>
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

    public:
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
        cout<<"Enter the left child of "<<x<<":";
        temp->left = BinaryTree();

        cout<<"Enter the right child of "<<x<<":";
        temp->right = BinaryTree();

        return temp;
    }

    vector<int>Preorder(Node*root) {
        vector<int>ans;

        stack<Node*>s;
        s.push(root);

        while(!s.empty()) {
            Node*temp = s.top();
            s.pop();

            ans.push_back(temp->data);

            if(temp->right) {
                s.push(temp->right);
            }

            if(temp->left) {
                s.push(temp->left);
            }
        }

        return ans;
    }
};

int main() {

    Tree t1;

    cout<<"Enter the root Node:";
    Node*root = t1.BinaryTree();

    vector<int>preorder = t1.Preorder(root);

    for(int i=0;i<preorder.size();i++) {
        cout<<preorder[i]<<" ";
    }

    return 0;
}