/*
* Optimised code for calculating the diameter of the tree  
*/

#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data) : data(data),left(NULL),right(NULL){}
};

class HDPair{
    public:
        int height;
        int diameter;
};

// Function for calculating the diameter
HDPair diameter(Node* root){
    HDPair p;
    if(root == NULL){
        p.height = 0;
        p.diameter = 0;
        return p;
    }
    HDPair left = diameter(root->left);
    HDPair right = diameter(root->right);
    p.height = 1 + max(left.height,right.height);
    int D1 = left.height + right.height;
    int D2 = left.diameter;
    int D3 = right.diameter;
    p.diameter = max(D1,max(D2,D3));
    return p;
}

Node* buildTree(){
    queue<Node*> q;
    int data;
    cout<<"[INFO] Enter the node : ";
    cin>>data;
    if(data == -1){
        cerr<<"[ERROR] Root node should not be NULL"<<endl;
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

// Function for inorder treaversal of tree

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
    cout<<"[INFO] Inorder traversal of binary tree : ";
    inorderTraversal(root);
    cout<<endl;
    HDPair p = diameter(root);
    cout<<"[INFO] Diameter of the tree : "<<p.diameter<<endl;
    return 0;
}