#include<iostream>
#include<vector>
using namespace std;

template<class T>
class max_heap{
    vector<T> v;
    void heapify(int index);
    public:
        max_heap(int default_size = 10){
            v.reserve(default_size);
        }
        bool empty();
        void push(T data);
        void pop();
        T getMax();
};

template<class T>
void max_heap<T>::heapify(int index){
    int left_child_index = index * 2;
    int right_child_index = left_child_index + 1;
    int max_index = index;
    if((left_child_index < v.size()) and (v[left_child_index] > v[max_index])){
        max_index = left_child_index;
    }
    else if((right_child_index < v.size()) and (v[right_child_index] > v[max_index])){
        max_index = right_child_index;
    }
    if(max_index != index){
        swap(v[max_index],v[index]);
        heapify(max_index);
    }
}

template<class T>
bool max_heap<T>::empty(){
    return (v.size() == 0) or (v.size() == 1);
}

template<class T>
void max_heap<T>::push(T data){
    v.push_back(data);
    int index = v.size() - 1;
    if(index == 0){
        v.push_back(data);
    }
    else{
        int parent_index = index/2;
        while((index > 1) and (v[parent_index] < v[index])){
            swap(v[parent_index],v[index]);
            index = parent_index;
            parent_index = parent_index/2;
        }
    }
}

template<class T>
void max_heap<T>::pop(){
    int index = v.size() - 1;
    swap(v[index],v[1]);
    v.pop_back();
    heapify(1);
}

template<class T>
T max_heap<T>::getMax(){
    return v[1];
}

int main(){
    max_heap<int> h;
    int arr[] = {5,4,6,3,7,2,8,1,9,10};
    for(int data : arr){
        h.push(data);
    }
    while(!h.empty()){
        cout<<h.getMax()<<" ";
        h.pop();
    }
    cout<<endl;
    return 0;
}