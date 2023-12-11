/*
* Program for preorder traversal of binary tree
*/

#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};


Node* buildTree(){
    int data;
    cout<<"[INFO] Enter the node : ";
    cin>>data;
    if(data == -1){
        return NULL;
    }
    Node* new_node = new Node(data);
    new_node->left = buildTree();
    new_node->right = buildTree();
    return new_node;
}

// Function for preorder traversal
void preoderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preoderTraversal(root->left);
    preoderTraversal(root->right);
}

int main(){
    Node* root = buildTree();
    preoderTraversal(root);
    return 0;
}