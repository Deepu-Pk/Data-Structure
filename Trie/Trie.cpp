#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
    public:
        char ch;
        unordered_map<char,Node*> hash;
        bool isTerminal;
        Node(char ch){
            this->ch = ch;
            isTerminal = false;
        }
};


class trie{
    Node* root;
    public:
        trie(){
            root = new Node('\0');
        }
        void insert(string word);
        bool search(string word);
};

void trie::insert(string word){
    Node* temp = root;
    for(char ch : word){
        if(temp->hash.count(ch) == 0){
            Node* new_node = new Node(ch);
            temp->hash[ch] = new_node;
        }
        temp = temp->hash[ch];
    }
    temp->isTerminal = true;
}

bool trie::search(string word){
    Node* temp = root;
    for(char ch : word){
        if(temp->hash.count(ch) == 0){
            return false;
        }
        temp = temp->hash[ch];
    }
    return temp->isTerminal;
}

int main(){
    trie t;
    string key;
    string words[] = {"Orange","Apple","News","New","Ape"};
    for(string word : words){
        t.insert(word);
    }
    cout<<"[INFO] Enter the key to search : ";
    cin>>key;
    bool present = t.search(key);
    if(present){
        cout<<"[INFO] "<<key<<"is present at list"<<endl;
    }
    else{
        cout<<"[INFO] "<<key<<" is not present at list"<<endl;
    }
    return 0;
}