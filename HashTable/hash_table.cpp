#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Node{
    public:
        string key;
        T value;
        Node* next;
        Node(string key,T value){
            this->key = key;
            this->value = value;
            next = NULL;
        }
};


template<typename T>
class hash_table{
    Node<T>** table;
    int ts,cs;
    void rehash();
    int hashFun(string key);
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
        Node<T>* searchKey(string key);
        void deleteKey(string key);
        void print();
        T& operator[](string key){
            Node<T>* temp = searchKey(key);
            if(temp == NULL){
                T object;
                insert(key,object);
                temp = searchKey(key);
            }
            return temp->value;
        }
};

template<typename T>
int hash_table<T>::hashFun(string key){
    int index = 0;
    int power = 1;
    for(auto ch : key){
        index = (index + (ch * power)) % ts;
        power = (power * 13) % ts;
    }
    return index;
}

template<typename T>
void hash_table<T>::rehash(){
    cs = 0;
    int old_ts = ts;
    Node<T>** old_table = table;
    ts = (old_ts * 2) + 1;
    table = new Node<T>*[ts];
    for(int i=0;i<ts;i++){
        table[i] = NULL;
    }

    for(int i=0;i<old_ts;i++){
        Node<T>* temp = old_table[i];
        while(temp != NULL){
            Node<T>* q = temp;
            insert(temp->key,temp->value);
            temp = temp->next;
            delete q;

        }
    }
}

template<typename T>
void hash_table<T>::insert(string key,T value){
    Node<T>* temp = new Node(key,value);
    int index = hashFun(key);
    
    temp->next = table[index];
    table[index] = temp;
    cs++;
    
    float load_factor = cs/float(ts);
    if(load_factor > 0.7){
        rehash();
    }
}

template<typename T>
Node<T>* hash_table<T>::searchKey(string key){
    int index = hashFun(key);
    Node<T>* temp = table[index];
    while(temp != NULL){
        if(temp->key == key){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

template<typename T>
void hash_table<T>::deleteKey(string key){
    int index = hashFun(key);
    Node<T>* p = table[index];
    Node<T>* q = p;
    while(p != NULL){
        if(p->key == key){
            if(p == q){
                table[index] = p->next;
            }
            else{
                q->next = p->next;
            }
            delete p;
        }
        q = p;
        p = p->next;
    }
}

template<typename T>
void hash_table<T>::print(){
    cout<<"=== Hash Table ==="<<endl;
    for(int i=0;i<ts;i++){
        cout<<"Bucket "<<i<<" : ";
        Node<T>* temp = table[i];
        while(temp != NULL){
            cout<<"["<<temp->key<<","<<temp->value<<"]->";
            temp = temp->next;
        }
        cout<<endl;
    }
}

int main(){
    string key;
    hash_table<int> hash;
    hash["Ramu"] = 27;
    hash["Manju"] = 28;
    hash["Raju"] = 30;
    hash["Krishna"] = 26;
    hash["Anju"] = 21;
    hash["Balu"] = 40;
    hash["Velu"] = 40;
    hash["Rama"] = 40;
    cout<<"Hash table"<<endl;
    hash.print();
    cout<<"[INFO] Enter the key to search : ";
    cin>>key;
    auto temp = hash.searchKey(key);
    if(temp != NULL){
        cout<<"[INFO] "<<key<<" is found at "<<temp<<" and value is "<<temp->value<<endl;
    }
    else{
        cout<<"[INFO] "<<key<<" is not found at hash table"<<endl;
    }
    cout<<"[INFO] Enter the key to delete : ";
    cin>>key;
    hash.deleteKey(key);
    hash.print();
    return 0;
}