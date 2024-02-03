/*
* Program for creating binary search tree
*/

#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data) : data(data),left(NULL),right(NULL){}
};

Node* bstInsert(Node* root, int data){
    if(root == NULL){
        return new Node(data);
    }

    if(data < root->data){
        root->left = bstInsert(root->left,data);
    }
    else{
        root->right = bstInsert(root->right,data);
    }
    return root;
}

void preorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    preorderTraversal(root->left);
    cout<<root->data<<" ";
    preorderTraversal(root->right);
}


int main(){
    Node* root = NULL;
    int arr[] = {5,7,9,4,11,70,2,1,10};
    for(auto data : arr){
        root = bstInsert(root,data);
    }
    cout<<"[INFO] Preorder traversal : ";
    preorderTraversal(root);
    cout<<endl;
    return 0;
}