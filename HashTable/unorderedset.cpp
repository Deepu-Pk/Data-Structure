/*
* Program for hash table using unordered_map STL
* Insertion : O(1)
* Deletion : 0(1)
* Search : O(1)
*/

#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s = {5,6,3,7,1,9};
    // Insert new item into set
    s.insert(10);

    // Print all elements in set
    cout<<"[INFO] The elemets are in set s : ";
    for(auto data : s){
        cout<<data<<" ";
    }
    cout<<endl;
    int key;
    cout<<"[INFO] Enter the key to search : ";
    cin>>key;
    if(s.find(key) != s.end()){
        cout<<"[INFO] "<<key<<" is  present at set s"<<endl;
    }
    else{
        cout<<"[INFO] "<<key<<" is not present at set s"<<endl;
    }
    // Delete the key
    s.erase(1);
    cout<<"[INFO] The elemets are in set s : ";
    for(auto data : s){
        cout<<data<<" ";
    }
    cout<<endl;
    return 0;
}