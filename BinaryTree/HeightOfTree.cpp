/*
* Building tree in level order
*/

#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};

Node* buildTree(){
    int data;
    cout<<"[INFO] Enter the node : ";
    cin>>data;
    if(data == -1){
        return NULL;
    }
    Node* root = new Node(data);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        cout<<"[INFO] Enter the node : ";
        cin>>data;
        if(data != -1){
            current->left = new Node(data);
            q.push(current->left);
        }
        cout<<"[INFO] Enter the node : ";
        cin>>data;
        if(data != -1){
            current->right = new Node(data);
            q.push(current->right);
        }
    }
    return root;
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1,h2);
}

int main(){
    Node* root = buildTree();
    cout<<"[INFO] Height of the tree  : "<<height(root)<<endl;
    return 0;
}