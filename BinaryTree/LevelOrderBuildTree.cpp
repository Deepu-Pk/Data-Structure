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
    cout<<"[INFO] Enter the node :";
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
        cout<<"[INFO] Enter the node :";
        cin>>data;
        if(data != -1){
            current->left = new Node(data);
            q.push(current->left);
        }
        cout<<"[INFO] Enter the node :";
        cin>>data;
        if(data != -1){
            current->right = new Node(data);
            q.push(current->right);
        }
    }
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        if(temp == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
            else{
                break;
            }
        }
        else{   
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root = buildTree();
    levelOrderTraversal(root);
    return 0;
}