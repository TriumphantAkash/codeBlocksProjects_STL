#include <iostream>
#include <deque>
//deque is basically short form of Double Ended Queue
//SEQUENCE CONTAINER
using namespace std;

int main()
{
    deque<int> my_deque;
    cout<<"deque initial size is : "<<my_deque.size()<<endl;
    my_deque.push_back(420);
    my_deque.push_back(9);
    my_deque.push_back(2);
    my_deque.push_back(11);
    cout <<"updated size of deque is : "<<my_deque.size()<< endl;

    deque<int>::iterator itr_begin = my_deque.begin();
    deque<int>::iterator itr_end = my_deque.end();
    deque<int>::iterator itr_temp = itr_begin;
    while(itr_temp != itr_end){
        cout<<*itr_temp<<" ";
        itr_temp++;
    }
    cout<<endl;
    return 0;
}
