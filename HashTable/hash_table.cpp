#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Node{
    public:
        string key;
        T  value;
        Node* next;
        Node(string key,T value){
            this->key = key;
            this->value = value;
            next = NULL;
        }
        ~Node(){
            if(next != NULL){
                delete next;
            }
        }
};

template<typename T>
class hash_table{
    int cs;
    int ts;
    Node<T>** table;
    int hashFunction(string key);
    void rehash();
    public:
        hash_table(int default_size = 7){
            cs = 0;
            ts = default_size;
            table = new Node<T>*[ts];
            for(int i=0;i<ts;i++){
                table[i] = NULL;
            }
        }
        void insert(string key,T value);
        void print();
        T* search(string key);
};

template<typename T>
void hash_table<T>::rehash(){
    cs = 0;   
    int old_ts = ts;
    Node<T>** old_table = table;
    ts = (2*old_ts) + 1;
    table = new Node<T>*[ts]; // Create n new table
    for(int i=0;i<ts;i++){
        table[i] = NULL;
    }

    for(int i=0;i<old_ts;i++){
        Node<T>* temp = old_table[i];
        while(temp != NULL){
            string key = temp->key;
            T value = temp->value;
            insert(key,value);
            temp = temp->next;
        }
        if(old_table[i] != NULL){
            delete old_table[i];
        }
    }
}

template<typename T>
int hash_table<T>::hashFunction(string key){
    int index = 0;
    int power = 1;
    for(auto ch : key){
        index = (index + (ch*power)) % ts;
        power = (power*29) % ts;
    }
    return index;
}

template<typename T>
void hash_table<T>::insert(string key,T value){ // Insert the node at head of the linked list
    int index = hashFunction(key);
    Node<T>* temp = new Node<T>(key,value);
    temp->next = table[index];
    table[index] = temp;
    cs++;
    float load_factor = cs/float(ts);
    if(load_factor > 0.7){
        rehash();
    }
}

template<typename T>
void hash_table<T>::print(){
    for(int i=0;i<ts;i++){
        cout<<"Bucket "<<i<<"->";
        Node<T>* temp = table[i];
        while(temp != NULL){
            cout<<"["<<temp->key<<","<<temp->value<<"]->";
            temp = temp->next;
        }
        cout<<endl;
    }
}
template<typename T>
T* hash_table<T>::search(string key){
    int index = hashFunction(key);
    Node<T>* temp = table[index];
    while(temp != NULL){
        if(temp->key == key){
            return &temp->value;
        }
        temp = temp->next;
    }
    return NULL;
}

int main(){
    string key;
    hash_table<int> hash;
    hash.insert("Deepu",27);
    hash.insert("Mithun",28);
    hash.insert("Amith",30);
    hash.insert("Sidharth",26);
    hash.insert("Nandanu",25);
    hash.insert("Sindhya",31);
    hash.insert("Nishil",40);
    hash.print();
    cout<<"[INFO] Enter key to serch : ";
    cin>>key;
    int* addr = hash.search(key);
    if(addr != NULL){
        cout<<"[INFO] value of "<<key<<" is "<<*addr<<endl;
    }
    else{
        cout<<"[INFO] key is not present at hash table"<<endl;
    }
    return 0;
}