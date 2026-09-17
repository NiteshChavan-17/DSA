#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
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

    vector<int>Inorder(Node*root) {
        vector<int>ans;
        stack<Node*>s;

        Node*temp = root;
        while(temp!=NULL || !s.empty()) {
            while(temp!=NULL) {
                s.push(temp);
                temp = temp->left;
            }

            temp = s.top();
            s.pop();

            ans.push_back(temp->data);
            temp = temp->right;
        }

        return ans;
    }
};

int main() {

    Tree t1;

    cout<<"Enter the root Node:";
    Node*root = t1.BinaryTree();

    vector<int>inorder = t1.Inorder(root);

    for(int i=0;i<inorder.size();i++) {
        cout<<inorder[i]<<" ";
    }

    return 0;
}