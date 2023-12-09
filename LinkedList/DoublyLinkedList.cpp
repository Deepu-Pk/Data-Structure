/*
    Implementation of Doubliy Linked list
*/
#include<iostream>
using namespace std;


// Defining a node
template<class T>
class node{
    public:
        node<T>* left;
        T data;
        node<T>* right;
        node(T data){
            this->data = data;
            left = right = nullptr;
        }
};

// Defining Doubly linked list

template<class T>
class list{
    private:
        node<T>* r;
        node<T>* t;
    public:
        list(){
            r = t = nullptr;
        }
        bool empty();
        void push_back(T data);
        void pop_back();
        T tail();
        void push_front(T data);
        void pop_front();
        T root();
        ~list(){
            while(r != nullptr){
                node<T>* temp = r;
                r = r->right;
                delete temp;
            }
           t = nullptr;
        }

};

// Check whether the list is empty or not
template<class T>
bool list<T>::empty(){ 
    if((r == nullptr) and (t == nullptr)){
        return true;
    }
    return false;
}

// Push element at end of the list
template<class T>
void list<T>::push_back(T data){
    node<T>* temp = new node(data);
    if(empty()){
        r = t = temp;
    }
    else{
        t->right = temp;
        temp->left = t;
        t = temp;
    }
}

// Pop the element at end of the list

template<class T>
void list<T>::pop_back(){
    node<T>* temp = t;
    if(t == r){
        delete temp;
        r = t = nullptr;
    }
    else{
        t = t->left;
        delete temp;
    }

}

// Return tail node
template<class T>
T list<T>::tail(){
    return t->data;
}

// Push data int front
template<class T>
void list<T>::push_front(T data){
    node<T>* temp = new node(data);
    if(empty()){
        r = t = temp;
    }
    else{
        temp->right = r;
        r->left = temp;
        r = temp;
    }
}

// pop element from root
template<class T>
void list<T>::pop_front(){
    if(r == t){
        delete r;
        r = t = nullptr;
    }
    else{
        node<T>* temp = r;
        r = r->right;
        delete temp;
    }
}

// return root element
template<class T>
T list<T>::root(){
    return r->data;
}

