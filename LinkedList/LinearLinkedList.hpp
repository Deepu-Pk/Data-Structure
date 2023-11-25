#include<iostream>
using namespace std;


template<class T>
class node{
    public:
        T data;
        node<T>* next;
};


template<class T>
class list{
    private:
        node<T>* head;
        node<T>* tail;
    public:
        list():head(nullptr),tail(nullptr){};
        void pushFront(T data);
        void popFront();
        void print();
        bool empty();
        void pushBack(T data);
        void popBack();
        void reverse();
        ~list(){
            while(head != nullptr){
                node<T>* temp = head;
                head = head->next;
                delete temp;
            }
            head = tail = nullptr;
        }
};


template<class T>
void list<T>::pushFront(T data){
    node<T>* temp = new node<T>;
    temp->data = data;
    if(head == nullptr){
        head = tail = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

template<class T>
void list<T>::popFront(){
    if(head == nullptr){
        return;
    }
    node<T>* temp = head;
    head = head->next;
    delete temp;
}

template<class T>
void list<T>::print(){
    node<T>* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}

template<class T>
void list<T>::pushBack(T data){
    node<T>* temp = new node<T>;
    temp->data = data;
    temp->next = nullptr;
    if(head == nullptr){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = tail->next;
    }
}

template<class T>
void list<T>::popBack(){
    if(tail == nullptr){
        return;
    }
    node<T>* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    tail = temp;
    delete temp->next;
    tail->next = nullptr;
}

template<class T>
void list<T>::reverse(){
    node<T>* prev = nullptr;
    node<T>* current = head;
    node<T>* next = nullptr;
    tail = head;
    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

