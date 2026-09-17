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

    vector<int>Postorder(Node*root) {

        if(root==NULL) {
            return {};
        }
        vector<int>ans;

        stack<Node*>s1;
        stack<Node*>s2;
        s1.push(root);

        while(!s1.empty()) {
            Node*temp = s1.top();
            s1.pop();

            s2.push(temp);

            if(temp->left) {
                s1.push(temp->left);
            }

            if(temp->right) {
                s1.push(temp->right);
            }
        }

        while(!s2.empty()) {
            Node*temp = s2.top();
            s2.pop();

            ans.push_back(temp->data);
            
        }

        return ans;
    }
};

int main() {

    Tree t1;

    cout<<"Enter the root Node:";
    Node*root = t1.BinaryTree();

    vector<int>postorder = t1.Postorder(root);

    for(int i=0;i<postorder.size();i++) {
        cout<<postorder[i]<<" ";
    }

    return 0;
}