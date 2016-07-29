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
    }

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

template<typename K, typename V>
class node{
public:
    K key;
    V value;
    node* next;
};

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


     void traverse(){
         for(int i =0;i<NUM_OF_BUCKETS;i++){
            std::cout<<"Bucket #"<<i<<") ";
            node<K, V>* temp = buckets[i];
            while(temp != NULL){
                std::cout<<temp->key<<","<<(temp->value).s<<" ";
                temp=temp->next;
            }
            std::cout<<std::endl;
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
    HashMap<int, string> hashMap;
    string str1;
    str1.getstring("akash");

    string str2;
    str2.getstring("ashesh");

    string str3;
    str3.getstring("ashutosh");

    hashMap.insert(2, str1);
    hashMap.insert(3, str2);
    hashMap.insert(3, str3);

    std::cout<<"the output of find function is: "<<hashMap.find(3).s<<std::endl;
    std::cout<<"******************************"<<std::endl;
    hashMap.traverse();
    hashMap.remove(2);
    std::cout<<"******************************"<<std::endl;
    hashMap.traverse();
    return 0;
}
