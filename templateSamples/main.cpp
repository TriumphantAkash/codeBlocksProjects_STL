#include <iostream>

using namespace std;
///////////////////////////////////////////////////
#define NUM_OF_BUCKETS 100

template<typename K>
unsigned int hash(K key);   //need to define this function later

template<typename K, typename V>
class node{
    K key;
    V value;
    node* next;
};

node* head = NULL;


template<typename K, typename V>
class HashMap
{
    bool flag = false;
    node* buckets[NUM_OF_BUCKETS];
    HashMap(){
        for(int i =0;i<NUM_OF_BUCKETS;i++){
            buckets[i] = NULL;
        }
    }

    public:
        void insert(K key, V value){
            int val = hash(key)%100;
            node* temp = buckets[val];
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
    return 0;
}
