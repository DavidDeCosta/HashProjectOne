#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
// David DeCosta


int hashKey(int key);
static const int TABLESIZE = 19;

class List{
private:
public:
    struct Record{
        string name;
        int key;
    };
    
    Record* HashTable[TABLESIZE]; //creates an array of pointers that will point to an object of record
    int count = 0;
    List(){
        for(int i=0; i < TABLESIZE;i++){
        HashTable[i] = new Record;
        HashTable[i]->name = "empty";
        HashTable[i]->key = 0;
        }
    }

    void linearInsertRecord(string name, int key){
        if(count == TABLESIZE){
            cout << "Table Full, Insertion Failed! \n";
            return;
        }
        int index = hashKey(key);
        while(HashTable[index]->key !=0 && HashTable[index]->key != -1){
            index = (index +1) % TABLESIZE;
        }   
            HashTable[index]->name = name;
            HashTable[index]->key=key;
            count++;
        }

    void linearDeleteRecord(int key){
        int index = hashKey(key);
        bool recordFound = true;
        while(recordFound){
            if(HashTable[index]->key = key){
                HashTable[index]->key = -1;
                HashTable[index]->name = "empty";
                cout << "Key Deleted! at index: " << index <<endl;
                recordFound = false;
            }
            else if(HashTable[index]->key = 0){
                cout << "Record not found. \n";
                recordFound =false;
            }
            else{
                index = (index +1) % TABLESIZE;
            }
        }
    }

  void linearSearchRecord(int key){
        int index = hashKey(key);
       // int temp = hashKey(key);
        bool recordFound = true;
        while(recordFound){
            if(HashTable[index]->key == key && HashTable[index]->key != -1){
                cout << "Key found! at index: " << index  << " Name: "<< HashTable[index]->name<<endl;
                recordFound = false;
            }
            else if(HashTable[index]->key == 0){
                cout << "Record not found.... \n";
                recordFound =false;
            }
            else{
                HashTable[index++];
            }
        }
    }

    void quadraticInsertRecord(string name,int key){
        int n =1;
        if(count == TABLESIZE){
            cout << "Table Full, Insertion Failed! \n";
            return;
        }
        int index = hashKey(key);
        while(HashTable[index]->key !=0 && HashTable[index]->key != -1){
            index = (index + n *n) % TABLESIZE;
            n++;
        }   
            HashTable[index]->name = name;
            HashTable[index]->key=key;
            count++;
        }
        
    void quadraticDeleteRecord(int key){
        int n =1;
        int index = hashKey(key);
        bool recordFound = true;
        while(recordFound){
            if(HashTable[index]->key = key){
                HashTable[index]->key = -1;
                HashTable[index]->name = "empty";
                cout << "Key Deleted! at index: " << index <<endl;
                recordFound = false;
            }
            else if(HashTable[index]->key = 0){
                cout << "Record not found. \n";
                recordFound =false;
            }
            else{
                index = (index + n *n) % TABLESIZE;
                n++;
            }
        }
    }

    void quadraticSearchRecord(int key){
        int n = 1;
        int index = hashKey(key);
       // int temp = hashKey(key);
        bool recordFound = true;
        while(recordFound){
            if(HashTable[index]->key == key && HashTable[index]->key != -1){
                cout << "Key found! at index: " << index  << " Name: "<< HashTable[index]->name<<endl;
                recordFound = false;
            }
            else if(HashTable[index]->key == 0){
                cout << "Record not found.... \n";
                recordFound =false;
            }
            else{
                index = (index + n *n) % TABLESIZE;
                n++;
            }
        }
    }
    
    void printList(){
        for(int i = 0; i < TABLESIZE; i++){
            cout << "Table index: " << i << " Name: " <<HashTable[i]->name << " Key: " << HashTable[i]->key <<endl;
        }
    }

};

int main(){

    int option;
    int optionTwo;
    List list;

    cout <<endl;
    cout << "What operation would you like to execute? (1)linear probing, (2) quadratic probing, (3) double hashing"<<
            "or (-99) to quit:" <<endl;
    cin >>option;
    while(option != -99){
        if(option == 1){
            cout << "(1) For insert, (2) for Delete, (3) for PrintList, (4) for Search, (-99) to exit \n";
            cin >> optionTwo;
            while(optionTwo != -99){
                if(optionTwo == 1){
                    list.linearInsertRecord("David DeCosta", 192); //2
                    list.linearInsertRecord("Emily DeCosta",444); //7
                    list.linearInsertRecord("Vincent DeCosta",345); //3
                    list.linearInsertRecord("Nathan DeCosta",892); //18
                    list.linearInsertRecord("Travis Ramsey", 192); //2
                    cout << "(1) For insert, (2) for Delete, (3) for PrintList, (4) for Search, (-99) to exit \n";
                    cin >> optionTwo;
                }
                else if(optionTwo == 2){
                    list.linearDeleteRecord(192);
                    cout << "(1) For insert, (2) for Delete, (3) for PrintList, (4) for Search, (-99) to exit \n";
                    cin >> optionTwo;
                }
                else if(optionTwo == 3){
                    list.printList();
                    cout << "(1) For insert, (2) for Delete, (3) for PrintList, (4) for Search, (-99) to exit \n";
                    cin >> optionTwo;
                }
                else if(optionTwo == 4){
                    list.linearSearchRecord(192);
                    cout << "(1) For insert, (2) for Delete, (3) for PrintList, (4) for Search, (-99) to exit \n";
                    cin >> optionTwo;
                }
                else{
                    cout << "(1) For insert, (2) for Delete, (3) for PrintList, (4) for Search, (-99) to exit \n";
                    cin >> optionTwo;
                }
            }
        }
        else if(option ==2){
            cout << "(1) For insert, (2) for Delete, (3) for PrintList, (4) for Search, (-99) to exit \n";
            cin >> optionTwo;
                while(optionTwo != -99){
                if(optionTwo == 1){
                    list.quadraticInsertRecord("Twon JuneBug",198);
                    list.quadraticInsertRecord("beetle boi",198);
                    list.quadraticInsertRecord("larry harry",198);
                    list.quadraticInsertRecord("sassy sally",344);
                    list.quadraticInsertRecord("christopher",999);
                    list.quadraticInsertRecord("jammy pammy",864);
                    cout << "(1) For insert, (2) for Delete, (3) for PrintList, (4) for Search, (-99) to exit \n";
                    cin >> optionTwo;
                }
                else if(optionTwo == 2){
                    list.quadraticDeleteRecord(198);
                    cout << "(1) For insert, (2) for Delete, (3) for PrintList, (4) for Search, (-99) to exit \n";
                    cin >> optionTwo;
                }
                else if(optionTwo == 3){
                    list.printList();
                    cout << "(1) For insert, (2) for Delete, (3) for PrintList, (4) for Search, (-99) to exit \n";
                    cin >> optionTwo;
                }
                else if(optionTwo == 4){
                    list.quadraticSearchRecord(198);
                    cout << "(1) For insert, (2) for Delete, (3) for PrintList, (4) for Search, (-99) to exit \n";
                    cin >> optionTwo;
                }
                else{
                    cout << "(1) For insert, (2) for Delete, (3) for PrintList, (4) for Search, (-99) to exit \n";
                    cin >> optionTwo;
                }
            }
        }
        else if(option ==3){
            }
        else{
            cout << "What operation would you like to execute? (1)linear probing, (2) quadratic probing, (3) double hashing"<<
            "or (-99) to quit:" <<endl;
            cin>>option;
        }
        cout << "What operation would you like to execute? (1)linear probing, (2) quadratic probing, (3) double hashing"<<
            "or (-99) to quit:" <<endl;
            cin>>option;
    }



    return 0;
}

int hashKey(int key){
    return key%TABLESIZE;
}