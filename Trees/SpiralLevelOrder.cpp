#include<iostream>
#include<vector>
#include<stack>
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

    vector<int>SpiralOrder(Node*root) {
        stack<Node*>s1;
        stack<Node*>s2;

        vector<int>ans;

        if(root==NULL) {
            return ans;
        }

        s1.push(root);

        while(!s1.empty() || !s2.empty()) {
            if(!s1.empty()) {
                while(!s1.empty()) {
                    Node*temp = s1.top();
                    s1.pop();
                    ans.push_back(temp->data);

                    if(temp->right) {
                        s2.push(temp->right);
                    }

                    if(temp->left) {
                        s2.push(temp->left);
                    }
                }
            }

            else{
                while(!s2.empty()) {
                    Node*temp = s2.top();
                    s2.pop();
                    ans.push_back(temp->data);

                    if(temp->left) {
                        s1.push(temp->left);
                    }

                    if(temp->right) {
                        s1.push(temp->right);
                    }
                }
            }
        }

        return ans;
    }

};


int main() {

    Tree t1;
    cout<<"Enter the root node:";
    Node*root = t1.BinaryTree();

    cout<<"Inorder Traversal: ";
    t1.Inorder(root);

    cout<<endl;

    vector<int>spiral = t1.SpiralOrder(root);

    for(int i=0;i<spiral.size();i++) {
        cout<<spiral[i]<<" ";
    }

    return 0;
}