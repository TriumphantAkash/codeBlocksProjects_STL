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
    str1.getstring("Santa Clara");

    string str2;
    str2.getstring("San Antonio");

    string str3;
    str3.getstring("San Jose");

    string str12;
    str12.getstring("Pheonix");

    string str4;
    str4.getstring("haha");
    string str5;
    str5.getstring("Agra");
    string str6;
    str6.getstring("Hyderabad");
    string str7;
    str7.getstring("Chennai");
    string str8;
    str8.getstring("Delhi");
    string str9;
    str9.getstring("Mumbai");
    string str10;
    str10.getstring("Singopore");
    string str11;
    str11.getstring("California");
    hashMap.insert(2, str1);
    hashMap.insert(3, str2);
    hashMap.insert(3, str3);
    hashMap.insert(4, str3);
    hashMap.insert(5, str4);
    hashMap.insert(6, str5);
    hashMap.insert(7, str6);
    hashMap.insert(8, str7);
    hashMap.insert(9, str8);
    hashMap.insert(23, str9);


    std::cout<<"the output of find function is: "<<hashMap.find(3).s<<std::endl;
    std::cout<<"******************************"<<std::endl;
    hashMap.traverse();
    hashMap.remove(8);
    std::cout<<"******************************"<<std::endl;
    hashMap.traverse();
    return 0;
}
