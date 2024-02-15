#include<iostream>
#include<vector>
using namespace std;

template<class T>
class min_heap{
    vector<T> v;
    void heapify(int index);
    public:
        min_heap(int default_size = 10){
            v.reserve(default_size);
        }
        bool empty();
        void push(T data);
        void pop();
        T getMin();
};

template<class T>
void min_heap<T>::heapify(int index){
    int left_child_index = index * 2;
    int right_child_index = left_child_index + 1;
    int min_index = index;
    if((left_child_index < v.size()) and (v[left_child_index] < v[min_index])){
        min_index = left_child_index;
    }
    else if((right_child_index < v.size()) and (v[right_child_index] < v[min_index])){
        min_index = right_child_index;
    }
    if(min_index != index){
        swap(v[min_index],v[index]);
        heapify(min_index);
    }
}

template<class T>
bool min_heap<T>::empty(){
    return (v.size() == 0) or (v.size() == 1);
}

template<class T>
void min_heap<T>::push(T data){
    v.push_back(data);
    int index = v.size() - 1;
    if(index == 0){
        v.push_back(data);
    }
    else{
        int parent_index = index/2;
        while((index > 1) and (v[parent_index] > v[index])){
            swap(v[parent_index],v[index]);
            index = parent_index;
            parent_index = parent_index/2;
        }
    }
}

template<class T>
void min_heap<T>::pop(){
    int index = v.size() - 1;
    swap(v[index],v[1]);
    v.pop_back();
    heapify(1);
}

template<class T>
T min_heap<T>::getMin(){
    return v[1];
}

int main(){
    min_heap<int> h;
    int arr[] = {5,4,6,3,7,2,8,1,9,10};
    for(int data : arr){
        h.push(data);
    }
    while(!h.empty()){
        cout<<h.getMin()<<" ";
        h.pop();
    }
    cout<<endl;
    return 0;
}