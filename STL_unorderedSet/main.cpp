#include <iostream>
#include<unordered_set>

using namespace std;

int main()
{
    unordered_set<string> my_u_set;
    my_u_set.insert("akash");
    my_u_set.insert("amit");
    my_u_set.insert("akshat");
    my_u_set.insert("akshara");

    unordered_set<string>::iterator i = my_u_set.find("Akash");
    if(i == my_u_set.end()){
        cout<<"element not preset!"<<endl;
    }

    //traverse
    for(string str:my_u_set){
        cout<<str<<" ";
    }
    cout<<endl;

    //Hash Table specific functions:
    //1) load factor: total elements / total buckets
    cout<<"load factor of the hash Table : "<<my_u_set.load_factor()<<endl;

    //2) Bucket number i.e. which bucket the supplied element is stored in
    cout<<"the element amit is sored in bucket # "<<my_u_set.bucket("amit")<<endl;

    //3) Bucket count : total number of buckets in the hash Table
    cout<<"the total number of buckets in the hash table is : "<<my_u_set.bucket_count()<<endl;
    return 0;
}
