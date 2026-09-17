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

    int Search(vector<int>& in, int left, int right, int val) {

        for(int i=left;i<=right;i++) {
            if(in[i]==val){
                return i;
            }
        }

        return -1;
    }


    Node*BuildTree(vector<int>& pre, vector<int>& in, int &preIndex, int left, int right) {

        if(left>right) {
            return NULL;
        }


        Node*root = new Node(pre[preIndex]);
        
        int Inindex = Search(in, left, right, pre[preIndex]);
        preIndex++;
        root->left = BuildTree(pre, in, preIndex, left, Inindex-1);
        root->right = BuildTree(pre, in, preIndex, Inindex+1, right);

        return root;
    }

    void preOrder(Node*root) {
        if(root==NULL) {
            return;
        }

        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
};

int main() {

    Tree t1;

    vector<int>pre = {3,9,20,15,7};
    vector<int>in = {9,3,15,20,7};

    int preIdx = 0;
    Node*root = t1.BuildTree(pre,in, preIdx,0, in.size()-1);

    t1.preOrder(root);
    return 0;
}