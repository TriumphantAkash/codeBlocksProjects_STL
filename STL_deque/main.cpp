#include <iostream>
#include <deque>
//deque is basically short form of Double Ended Queue
//SEQUENCE CONTAINER
using namespace std;

void add_element(vector<int>* v1){
    int n = 0;
    cout<<"enter element to add"<<endl;
    cin>>n;
    v1->push_back(n);
}

//[UNIVERSAL WAY FOR TRAVERSING A CONTAINER]
void print_approach1(vector<int>* v1){
    vector<int>::iterator itr_start = (*v1).begin();    //this is an experiment (try to understand ;) )
    vector<int>::iterator itr_end = v1->end();
    vector<int>::iterator itr_temp = itr_start;

    while(itr_temp != itr_end){
        cout<<*itr_temp<<endl;
        itr_temp++;
    }
}

//Using normal Array index method
void print_approach2(vector<int>* v1){
    for(int i =0;i<v1->size();i++){
        cout<<(*v1)[i]<<endl;
    }
}

//using vector at() method
void print_approach3(vector<int>* v1){
    for(int i = 0;i<v1->size();i++){
        cout<<v1->at(i)<<endl;
    }
}

//using for each loop
void print_approach4(vector<int>* v1){
    for(int element: *v1){
        cout<<element<<endl;
    }
}

void sort_vector(vector<int>* v1){
    //Remember: Algorithms directly work on iterator, not on elements
    vector<int>::iterator itr1 = v1->begin();
    vector<int>::iterator itr2 = v1->end();
    sort(itr1, itr2);
}

int main()
{
    deque<int> my_deque;
    cout<<"deque initial size is : "<<my_deque.size()<<endl;
  do{
        cout<<"select a choice"<<endl;
        cout<<"1) add element to vector"<<endl;
        cout<<"21) print elements of vector using iterators"<<endl;
        cout<<"22) print elements of vector like normal Arrays"<<endl;
        cout<<"23) print elements using at() function"<<endl;
        cout<<"24 print elements using forEach loop"<<endl;
        cout<<"3) remove element from the vector"<<endl;
        cout<<"4) sort elements in the vector"<<endl;
        cout<<"99) exit"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            add_element(&v);
            break;
        case 21:
            print_approach1(&v);
            break;
        case 22:
            print_approach2(&v);
            break;
        case 23:
            print_approach3(&v);
            break;
        case 24:
            print_approach4(&v);
            break;
        case 4:
            sort_vector(&v);
            break;
        case 99:
            break;
        }
	}while(choice != 99);
    return 0;
}
