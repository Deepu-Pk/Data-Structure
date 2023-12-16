/*
* Program for calculating the dimeter of the binary tree
*/
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

// Node for binary tree
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data) : data(data),left(NULL),right(NULL){}
};

// Function for building tree
Node* buildTree(){
    queue<Node*> q;
    int data;
    cout<<"[INFO] Enter the node : ";
    cin>>data;
    if(data == -1){
        cout<<"[ERROR] Root can not NULL"<<endl;
        return NULL;
    }
    Node* root = new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<"[INFO] Enter the node : ";
        cin>>data;
        if(data != -1){
            temp->left = new Node(data);
            q.push(temp->left);
        }
        cout<<"[INFO] Enter the node : ";
        cin>>data;
        if(data != -1){
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
    return root;
}

// Function for calculating height of the tree
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1,h2);
}

// Function for calculating the diameter of the tree
int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int d1 = h1 + h2;
    int d2 = height(root->left);
    int d3 = height(root->right);
    return max(d1,max(d2,d3));
}

// Function for printinf tree inorder traversal
void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){
    Node* root = buildTree();
    inorderTraversal(root);
    cout<<endl;
    cout<<"[INFO] Diameter of the tree : "<<diameter(root)<<endl;
    return 0;
}