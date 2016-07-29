#include <iostream>
#include <string.h>
using namespace std;
///////////////////////////////////////////////////
#define NUM_OF_BUCKETS 100

//wrote a custom string class in order to overload == and + operator
class string {
    public:
    char *s;
    int size;
    void getstring(char *str)
    {
        size = strlen(str);
        s = new char[size];
        strcpy(s,str);
        std::cout<<s<<std::endl;
    }

    void operator+(string ob){
        std::cout<<"current s is:"<<s<<std::endl;
       // std::cout<<"passed string is:"<<ob<<std::endl;
        size = size+ob.size;
        std::cout<<"new size is:"<<size<<std::endl;
        //s = new char[size+5];
        strcat(s,ob.s);
        std::cout<<"\nConcatnated String is: "<<s;
    }

     bool operator==(string ob){
        if(strcmp(s, ob.s) == 0){
            return true;
        }else{
            return false;
        }
    }
};

template<typename K>
unsigned int hashFunc(K key);   //need to define this function later

template<typename K, typename V>
class node{
    K key;
    V value;
    node* next;
};

//node<K, V>* head = NULL;


template<typename K, typename V>
class HashMap
{
private:
    bool flag = false;
    node<K, V>* buckets[NUM_OF_BUCKETS];

public:
    HashMap(){
        node<K, V>* head = NULL;
        for(int i =0;i<NUM_OF_BUCKETS;i++){
            buckets[i] = NULL;
        }
    }

    void insert(K key, V value){
            int val = hashFunc(key)%100;
            node<K, V>* temp = buckets[val];
/*
            while(temp != NULL){
                if(strcmp(temp->key,key) == 0){
                    flag = true;
                    strcpy(temp->value, value);
                    break;
                }
                temp=temp->next;
            }

            if(flag == false){
                struct node* newNode = (struct node*)malloc(sizeof(node));
                strcpy(newNode->key, key);
                strcpy(newNode->value,value);
                newNode->next = NULL;
                temp->next = newNode;
            }
*/
    }
        /*

        boolean find(string key){
              int val = hash(key)%100;
              struct node* temp = bucket[val];


              while(temp != NULL){
                if(strcmp(temp->key,key) == 0){
                    return true;
                }
                temp=temp->next;
              }
              return false;

        }

        void delete(string key){
            int val = hash(key)%100;
            struct node* temp = bucket[val];
            struct node * prev = temp;

            while(temp != NULL){
                if(strcmp(temp->key,key) == 0){

                    strucy node* temp1= temp->next;
                    prev = temp1;
                    free(temp->next);
                    temp->next = temp1;
                    break;
                }
                prev = temp;
                 temp=temp->next;
            }

        }
        */


};
///////////////////////////////////////////////////

int main()
{
    HashMap<int, int> hashMap;
    hashMap.insert(2,3);
    return 0;
}
