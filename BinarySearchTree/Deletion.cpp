/*
*   Program for delete the node 
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

Node* insertBST(Node* root,int data){
    if(root == NULL){
        return new Node(data);
    }

    else if(data < root->data){
        root->left = insertBST(root->left,data);
    }
    else{
        root->right = insertBST(root->right,data);
    }
    return root;
}

Node* findMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

// Function for delete the node
Node* removeNode(Node* root,int key){
    if(root == NULL){
        return NULL;
    }
    else if(key < root->data){
        root->left = removeNode(root->left,key);
    }
    else if(key > root->data){
        root->right = removeNode(root->right,key);
    }
    else{
        if((root->left == NULL) and (root->right == NULL)){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else{
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = removeNode(root->right,temp->data);
        }
    }
    return root;
}

void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){
    Node* root = NULL;
    int key;
    int arr[] = {3,6,8,1,12,34,55,23,11,76,45};
    for(int x : arr){
        root = insertBST(root,x);
    }
    inorderTraversal(root);
    cout<<"[INFO] Enter the key to delete : ";
    cin>>key;
    root = removeNode(root,key);
    inorderTraversal(root);
    return 0;
}
