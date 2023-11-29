/*
 Queue Data structure using array 
*/

#include<iostream>
using namespace std;

template<class type>
class Queue{
    private:
        int f;
        int r;
        int size;
        type* Q;
    public:
        Queue(){
            f = r = 0;
            size = 11;
            Q = new type[11];
        }
        Queue(int size){
            f = r = 0;
            this->size = size+1;
            Q = new type[this->size];
        }
        void enqueue(type data);
        void dequeue();
        type front();
        bool empty();
        bool full();
        ~Queue(){
            delete[] Q;
        }
};

template<class type>
bool Queue<type>::empty(){
    return r == f;
}

template<class type>
bool Queue<type>::full(){
    if((r+1) % size == f){
        return true;
    }
    return false;
}

template<class type>
void Queue<type>::enqueue(type data){
    if(!full()){
        r = (r+1) % size;
        Q[r] = data;
    }
    else{
        cerr<<"[ERROR] Queue overflow"<<endl;
    }
}

template<class type>
void Queue<type>::dequeue(){
    if(!empty()){
        f = (f+1) % size;
    }
    else{
        cerr<<"[ERROR] Queue underflow"<<endl;
        abort();
    }
}

template<class type>
type Queue<type>::front(){
    if(!empty()){
        return Q[f+1];
    }
    else{
        cerr<<"[ERROR] Queue underflow"<<endl;
        abort();
    }
}
