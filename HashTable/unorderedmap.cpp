// Program to implement the hash table using STL 

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    unordered_map<string,int> menu;
    string key;
    menu["Pizza"] = 300;
    menu["Coffee"] = 20;
    menu["Tea"] = 10;
    menu["Burgger"] = 200;
    menu["Sandwitch"] = 100;
    cout<<"[INFO] Enter the item : ";
    cin>>key;
    if(menu.count(key) == 0){
        cout<<"[INFO] "<<key<<"is not available in menu"<<endl;
    }
    else{
        cout<<"[INFO] "<<key<<" is available and the price of "<<key<<" is "<<menu[key]<<endl; 
    }

    // Iterate all items im menu
    for(pair<string,int> item : menu){
        cout<<item.first<<"->"<<item.second<<endl;
    }
    return 0;
}