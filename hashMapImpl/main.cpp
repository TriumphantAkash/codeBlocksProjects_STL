#include <iostream>
#include <string.h>

///////////////////////////////////////////////////
#define NUM_OF_BUCKETS 10

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
      //  std::cout<<s<<std::endl;
    }

    int operator*(int a){
        int sum=0;
        for(int i=0;i<size;i++){
            sum+=s[i];
        }
        return sum*a;
    }

    void operator=(string ob){
        //std::cout<<"current s is:"<<s<<std::endl;
       // std::cout<<"passed string is:"<<ob<<std::endl;
        size = std::max(size,ob.size);
       // std::cout<<"new size is:"<<size<<std::endl;
        s = new char[size+1];
        strcpy(s,ob.s);
    }

    void operator+(string ob){
       // std::cout<<"current s is:"<<s<<std::endl;
       // std::cout<<"passed string is:"<<ob<<std::endl;
        size = size+ob.size;
       // std::cout<<"new size is:"<<size<<std::endl;
        //s = new char[size+5];
        strcat(s,ob.s);
      //  std::cout<<"\nConcatnated String is: "<<s;
    }

     bool operator==(string ob){
        if(strcmp(s, ob.s) == 0){
            return true;
        }else{
            return false;
        }
    }
};
   //need to define this function later

template<typename K, typename V>
class node{
public:
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
    unsigned long hashFunc(K key){
        return key*314;
    }

    HashMap(){
        node<K, V>* head = NULL;
        for(int i =0;i<NUM_OF_BUCKETS;i++){
            buckets[i] = NULL;
        }
    }

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

            while(temp != NULL){
                if(temp->key == key){
                    flag = true;
                    temp->value = value;
                    break;
                }
                temp=temp->next;
            }

            if(flag == false){
                node<K, V>* newNode = new node<K, V>();
                newNode->key = key;
                newNode->value = value;
                newNode->next = NULL;
                temp = newNode;
            }

    }


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
/*
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
    HashMap<int, string> hashMap;
    string str1;
    str1.getstring("akash");

    string str2;
    str2.getstring("ashesh");

    hashMap.insert(2, str1);
    hashMap.insert(3, str2);

    std::cout<<"the output of find function is: "<<hashMap.find(2).s<<std::endl;

    return 0;
}
