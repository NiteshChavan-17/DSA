#include<iostream>
#include<vector>
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

class Tree {

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
        cout<<"Enter the left child of "<<x<<":";
        temp->left = BinaryTree();

        cout<<"Enter the right child of "<<x<<":";
        temp->right = BinaryTree();

        return temp;
    }

    void find(Node*root, int pos, int &l, int &r) {

        if(root==NULL) {
            return;
        }

        l = min(pos,l);
        r = max(pos,r);

        find(root->left, pos-1, l, r);
        find(root->right, pos+1, l, r);
    }

    vector<int>TopView(Node*root)  {

        int l = 0;
        int r = 0;

        find(root,0,l,r);

        int size = r-l+1;
        vector<int>ans(size);
        vector<bool>visited(size,0);

        queue<Node*>q;
        queue<int>index;

        q.push(root);
        index.push(-1 * l);

        while(!q.empty()) {
            Node*temp = q.front();
            q.pop();

            int pos = index.front();
            index.pop();

            if(!visited[pos]) {
                visited[pos] = 1;
                ans[pos] = temp->data;
            }

            if(temp->left) {
                q.push(temp->left);
                index.push(pos-1);
            }

            if(temp->right) {
                q.push(temp->right);
                index.push(pos+1);
            }
        }

        return ans;
    }
};

int main() {

    Tree t1;

    cout<<"Enter the root Node:";
    Node*root = t1.BinaryTree();

    vector<int>topView = t1.TopView(root);

    for(int i=0;i<topView.size();i++) {
        cout<<topView[i]<<" ";
    }

    return 0;
}