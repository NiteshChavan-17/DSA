#include<iostream>
#include<queue>
#include<vector>
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

    vector<int>RightView(Node*root) {
        queue<Node*>q;
        vector<int>ans;

        q.push(root);
        while(!q.empty()) {
            int n = q.size();

            ans.push_back(q.front()->data);

            while(n--) {
                Node*temp = q.front();
                q.pop();

                if(temp->right) {
                    q.push(temp->right); 
                }

                if(temp->left) {
                    q.push(temp->left);
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

    vector<int>rightview = t1.RightView(root);

    cout<<"Right view of tree:";
    for(int i=0;i<rightview.size();i++) {
        cout<<rightview[i]<<" ";
    }

    return 0;
}