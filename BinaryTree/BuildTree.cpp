/*
* Build Binary Tree from preorder traversal
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

// Function for buiding binary tree
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

int main(){
    Node* root = buildTree();
    return 0;
}