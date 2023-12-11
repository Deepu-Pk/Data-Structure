/*
* Program for inorder traversal of binary tree
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

// Function postorder traversal
void postorderTravrsal(Node* root){
    if(root == NULL){
        return;
    }
    postorderTravrsal(root->left);
    postorderTravrsal(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = buildTree();
    postorderTravrsal(root);
    return 0;
}