#include <iostream>
#include <string.h>

#define NUM_OF_BUCKETS 10

//wrote a custom string class in order to overload ==, =, * and + operator
class string {
public:
    char *s;
    int size;
    string(char* str){
        size = strlen(str);
        s = new char[size];
        strcpy(s,str);
    }
    string(){}
    int operator*(int a){
        int sum=0;
        for(int i=0;i<size;i++){
            sum+=s[i];
        }
        return sum*a;
    }

    void operator=(string ob){
        size = std::max(size,ob.size);
        s = new char[size+1];
        strcpy(s,ob.s);
    }

    void operator+(string ob){
        size = size+ob.size;
        strcat(s,ob.s);
    }

     bool operator==(string ob){
        if(strcmp(s, ob.s) == 0){
            return true;
        }else{
            return false;
        }
    }
};

//overloading operator<< for our string class
std::ostream &operator<<(std::ostream &os, string const &obj) {
    return os << obj.s;
}

//Node class
template<typename K, typename V>
class node{
public:
    K key;
    V value;
    node* next;
};

//HashMap class
template<typename K, typename V>
class HashMap
{
private:
    bool flag = false;
    node<K, V>* buckets[NUM_OF_BUCKETS];

public:
    //a simple hashfunction
    //input: any type of key (handles string because * operator is overloaded)
    //output: an unsigned long number
    unsigned long hashFunc(K key){
        return key*314;
    }

    HashMap(){
        node<K, V>* head = NULL;
        for(int i =0;i<NUM_OF_BUCKETS;i++){
            buckets[i] = NULL;
        }
    }

    //for inserting any key, value pair in the hashMap
    //input: key - value pair
    //output: void
    void insert(K key, V value){
        int val = hashFunc(key)%10;
        node<K, V>* temp = buckets[val];

        if(buckets[val] == NULL){
            node<K, V>* newNode = new node<K, V>();
            newNode->key = key;
            newNode->value = value;
            newNode->next = NULL;
            buckets[val] = newNode;
            return;
        }

        while(temp->next != NULL){
            if(temp->key == key){
                flag = true;
                temp->value = value;
                return;
            }
            temp=temp->next;
        }
        if(temp->key == key){
            temp->value = value;
            return;
        }else{
            node<K, V>* newNode = new node<K, V>();
            newNode->key = key;
            newNode->value = value;
            newNode->next = NULL;
            temp->next = newNode;
        }

    }

    //for traversing through the hashmap, prints all the key-value pairs in the map
    //input: void
    //output: void
    void traverse(){
        for(int i =0;i<NUM_OF_BUCKETS;i++){
            std::cout<<"Bucket #"<<i<<") ";
            node<K, V>* temp = buckets[i];
            while(temp != NULL){
                std::cout<<temp->key<<","<<(temp->value)<<" ";
                temp=temp->next;
            }
            std::cout<<std::endl;
        }
    }

    //for finding a corresponding value for the supplied key
    //input: key
    //output: corresponding value for the key (last value in the map, if key not present)
    V find(K key){
        int val = hashFunc(key)%10;;
        node<K, V>* temp = buckets[val];


        while(temp != NULL){
            if(temp->key == key){
                return temp->value;
            }
            temp=temp->next;
        }
        return temp->value;
    }

    //for removing a key value pair from the map
    //input: key
    //output: void
    void remove(K key){
        int val = hashFunc(key)%10;
        if(buckets[val]->key==key){                //need to separately handle this case because head of list changes if want to delete the first element
            node<K, V>* temp = buckets[val];
            buckets[val] = buckets[val]->next;
            delete temp;
            return;
        }
        node<K, V>* temp = buckets[val];
        struct node<K, V> * prev = temp;
        while(temp != NULL){
            if(temp->key==key){
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp=temp->next;
        }

    }


};
///////////////////////////////////////////////////

int main()
{
    HashMap<string, int> hashMap;

    string str1("Santa Clara");
    string str2("San Antonio");
    string str3("San Jose");
    string str4("Pheonix");
    string str5("Agra");
    string str6("Hyderabad");
    string str7("Chennai");
    string str8("Delhi");
    string str9("Mumbai");
    string str10("Singopore");
    string str11("Boston");

    hashMap.insert(str1, 2);
    hashMap.insert(str2, 3);
    hashMap.insert(str3, 3);
    hashMap.insert(str3, 4);
    hashMap.insert(str4, 5);
    hashMap.insert(str5, 6);
    hashMap.insert(str6, 7);
    hashMap.insert(str7, 8);
    hashMap.insert(str8, 9);
    hashMap.insert(str9, 23);
/*
    hashMap.insert(1.2, 2);
    hashMap.insert(2.3, 3);
    hashMap.insert(5.5, 3);
    hashMap.insert(6.7, 4);
    hashMap.insert(9.8, 5);
    hashMap.insert(14.3, 6);
    hashMap.insert(89.43, 7);
    hashMap.insert(12.12, 8);
    hashMap.insert(12.12, 9);
    hashMap.insert(12.14, 23);

*/
    std::cout<<"the output of find function is: "<<hashMap.find(str7)<<std::endl;
    hashMap.traverse();
    hashMap.remove(str2);
    std::cout<<"/////////////////////////////////////////////////"<<std::endl;
    hashMap.traverse();
    return 0;
}
