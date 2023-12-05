/*
    Implementation of stack using array
*/

#include<iostream>
using namespace std;

template<class T>
class stack{
    private:
        int t;
        T *s;
        int size;
    public:
        stack(){
            s = new T[10];
            t = -1;
            size = 10;
        }
        stack(int size){
            s = new T[size];
            t = -1;
            this->size = size;
        }
        bool empty();
        bool full();
        void push(T data);
        void pop();
        T top();
        ~stack(){
            delete[] s;
        }
};

// Check the stack whether empty or not
template<class T>
bool stack<T>::empty(){
    return t == -1;
}

// Check the stack is full or not
template<class T>
bool stack<T>::full(){
    return t == size;
}

// Push operation
template<class T>
void stack<T>::push(T data){
    if(!full()){
        s[++t] = data;
        return;
    }
    cerr<<"[ERROR] Stack overflow"<<endl;
    abort();
}
// Pop operation
template<class T>
void stack<T>::pop(){
    if(!empty()){
        t--;
        return;
    }
    cerr<<"[ERROR] Stack underflow"<<endl;
    abort();
}

// Return top of the element
template<class T>
T stack<T>::top(){
    if(!empty()){
        return s[t];
    }
    cerr<<"[ERROR] Stack underflow"<<endl;
    abort();
}
