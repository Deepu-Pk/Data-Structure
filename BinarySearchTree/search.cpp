/*
* Search an element in binary search search tree
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



// Function for insert a element into BST
Node* insertBST(Node* root, int data){
    if(root == NULL){
        return new Node(data);
    }
    if(root->data > data){
        root->left = insertBST(root->left,data);
    }
    else{
        root->right = insertBST(root->right,data);
    }
    return root;
}


// Preorder traversal of BST
void preorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    preorderTraversal(root->left);
    cout<<root->data<<endl;
    preorderTraversal(root->right);
}

// Search an element in BST

bool searchBST(Node* root,int data){
    if(root == NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }
    if(data < root->data){
        return searchBST(root->left,data);
    }
    else{
        return searchBST(root->right,data);
    }
}

int main(){
    Node* root = NULL;
    int key;
    int arr[] = {5,7,9,4,11,70,2,1,10};
    for(auto x : arr){
        root = insertBST(root,x);
    }
    preorderTraversal(root);
    cout<<"[INFO] Enter the element to search : ";
    cin>>key;
    bool found = searchBST(root,key);
    if(found){
        cout<<"[INFO] "<<key<<" is found "<<endl;
    }
    else{
        cout<<"[INFO] "<<key<<" is not found"<<endl;
    }
    return 0;
}