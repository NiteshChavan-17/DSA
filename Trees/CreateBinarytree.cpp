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

int main() {
    queue<Node*>q;

    int x;
    cout<<"Enter the root element:";
    cin>>x;
    Node*root = new Node(x);

    q.push(root);
    while(!q.empty()) {
        Node*temp = q.front();
        q.pop();

        int first;
        cout<<"Enter the left child of "<<temp->data<<":";
        cin>>first;
        if(first!=-1) {
            temp->left = new Node(first);
            q.push(temp->left);
        }

        int second;
        cout<<"Enter the right child of "<<temp->data<<":";
        cin>>second;
        if(second!=-1) {
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }
}