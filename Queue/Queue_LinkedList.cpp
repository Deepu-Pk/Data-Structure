/*
    Queue data structure using linked list
*/

#include<iostream>
using namespace std;

template<typename T>
class queue{
    class Node{
        public:
            T data;
            Node* next;
            Node(T data) : data(data),next(nullptr) {}
    };
    Node* head;
    Node* tail;
    public:
        queue() : head(nullptr),tail(nullptr) {}
        bool empty();
        void push(T data);
        void pop();
        T front();
        ~queue(){
            while(head != nullptr){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
        }
};

template<typename T>
bool queue<T>::empty(){
    return (head == nullptr) and (tail == nullptr);
}

template<typename T>
void queue<T>::push(T data){
    Node* temp = new Node(data);
    if(temp == nullptr){
        cerr<<"[ERROR] Queue is full"<<endl;
        exit(0);
    }
    if(empty()){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

template<typename T>
void queue<T>::pop(){
    if(empty()){
        cerr<<"[ERROR] Queue is empty"<<endl;
        exit(0);
    }
    Node* temp = head;
    if(head == tail){
        head = tail = nullptr;
    }
    else{
        head = head->next;
    }
    delete temp;
}

template<typename T>
T queue<T>::front(){
    if(empty()){
        cerr<<"[ERROR] Queue is empty"<<endl;
        exit(0);
    }
    return head->data;
}

int main(){
    queue<int> q;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    for(int data : arr){
        q.push(data);
    }
    while(!q.empty()){
        cout<<q.front()<<",";
        q.pop();
    }
    return 0;
}
