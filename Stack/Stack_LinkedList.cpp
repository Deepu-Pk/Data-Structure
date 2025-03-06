/*
 Stack using linked linked list
*/

#include<iostream>
using namespace std;

template<typename T>
class stack{
    class Node{
        public:
            T data;
            Node* next;
            Node(T data) : data(data),next(nullptr) {}
    };
    Node* head;
    public:
        stack() : head(nullptr) {}
        bool empty();
        void push(T data);
        void pop();
        T top();
        ~stack(){
            while(head != nullptr){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
};

template<typename T>
bool stack<T>::empty(){
    return head == nullptr;
}

template<typename T>
void stack<T>::push(T data){
    Node* temp = new Node(data);
    if(temp == nullptr){
        cerr<<"[ERROR] Stack overflow"<<endl;
        exit(0);
    }
    temp->next = head;
    head = temp;
}

template<typename T>
void stack<T>::pop(){
    if(empty()){
        cerr<<"[ERROR] Stack underflow"<<endl;
        exit(0);
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

template<typename T>
T stack<T>::top(){
    if(empty()){
        cerr<<"[ERROR] Stack underflow"<<endl;
        exit(0);
    }
    return head->data;
}

int main(){
    stack<int> s;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    for(int data : arr){
        s.push(data);
    }
    while(!s.empty()){
        cout<<s.top()<<",";
        s.pop();
    }
    return 0;
}