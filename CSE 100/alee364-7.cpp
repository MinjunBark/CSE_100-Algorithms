#include <iostream>
#include <list>
using namespace std;

class HashTable{
    public:
        list<int> *hashTable;

        HashTable(){ //Constructor of hashtable
            hashTable = NULL;
        };

        ~HashTable(){
            if(hashTable != NULL){ //Destuctor of hashtable
                delete[] hashTable;
            }
        }

    void createHashTable(int size){
        hashTable = new list<int>[size]; //creating a new list of input (size) for hashtable
    }
    
    void insert(int key, int size){ //
        hashTable[key%size].push_front(key); //inserting key to the front of linked list
    }

    void search(int key, int size){
        list<int> newTable = hashTable[key%size];
        list<int>::iterator it;
        int i = 0;
        if(newTable.empty()){ //if table is empty -> Not_Found
            cout << key <<  ":NOT_FOUND" << ";" << endl;
        }
        else{
            for(it = newTable.begin(); it != newTable.end(); it++){ //search through hashtable slots for key 
                if(*it == key){
                    cout << key << ":FOUND_AT"<< (key%size) << "," << i << ";" << endl;
                    return;
                }
                i++;
            }
            cout << key << ":NOT_FOUND" <<";" << endl;
        }
    }
    bool del(int key, int size){
        list<int> newTable = hashTable[key%size];
        list<int>::iterator it;
        if(newTable.empty()){ 
            return false;
        }
        else{
            for(it = newTable.begin(); it !=newTable.end(); it++){
                if(*it == key){
                    newTable.erase(it); //if key is found delete it from table 
                    hashTable[key%size] = newTable;
                    return true;
                }
            }
            return false;
        }
    }

    void output(int size){
        list<int> newTable;
        list<int>:: iterator it;
        for(int i = 0; i < size; i++){
            newTable = hashTable[i];
            if(newTable.empty()){
                cout <<i << ":" << ";" << endl;
            }
            else{
                cout << i << ":";
                for(it = newTable.begin(); it != newTable.end(); it++){
                    cout << *it << "->";
                }
                cout <<";"<< endl;
            }
        }
    }
};

int main (){
    int size;
    int key; //k 
    char user_input;
    
    cin >> size; //m
    HashTable hashObj;
    hashObj.createHashTable(size);

    while(user_input != 'e'){
        cin >> user_input;

        if(user_input == 'i'){
            cin >> key;
            hashObj.insert(key,size);
        }
        else if(user_input == 'd'){
            cin >> key;
            if(hashObj.del(key,size)){
                cout << key << ":DELETED" << ";" << endl;
            }
            else{
                cout << key << ":DELETE_FAILED"<< ";" << endl;
            }
        }
        else if(user_input == 's'){
            cin >> key;
            hashObj.search(key,size);
        }
        else if(user_input == 'o'){
            hashObj.output(size);
        }
    }
    return 0;
}