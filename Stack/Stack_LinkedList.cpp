/*
 Stack using linked linked list
*/
#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
        T data;
        Node<T>* next;
        Node(T data){
            this->data = data;
            next = nullptr;
        }
};

template<class T>
class stack{
    private:
        Node<T>* root;
    public:
        stack(){
            root = nullptr;
        }
        bool empty();
        bool full();
        void push(T data);
        void pop();
        T top();
        ~stack(){
            while(root != nullptr){
                Node<T>* temp = root;
                root = root->next;
                delete temp;
            }
        }

};


template<class T>
bool stack<T>::empty(){
    return root == nullptr;
}

template<class T>
bool stack<T>::full(){
    Node<T>* temp = new Node<T>(10);
    if(temp == nullptr){
        return true;
    }
    delete temp;
    return false;
}

template<class T>
void stack<T>::push(T data){
    if(!full()){
        Node<T>* temp = new Node<T>(data);
        temp->next = root;
        root = temp;
        return;
    }
    cerr<<"[ERROR] Stack overflow"<<endl;
    abort();
}

template<class T>
void stack<T>::pop(){
    if(!empty()){
        Node<T>* temp = root;
    
        root = root->next;
        delete temp;
        return;
    }
    cerr<<"[ERROR] Stack underflow"<<endl;
    abort();
}

template<class T>
T stack<T>::top(){
    if(!empty()){
        return root->data;
    }
    cerr<<"[ERROR] Stack underflow"<<endl;
    abort();
}


int main(){
    stack<int> s;
    s.push(10);
    s.push(5);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}