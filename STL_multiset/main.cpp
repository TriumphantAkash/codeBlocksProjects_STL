/*
THE ONLY DIFFERENCE BETWEEN SET AND MULTISET IS THAT
MULTISET CAN STORE DUPLICATE VALUES
*/
#include <iostream>
#include<set>
using namespace std;

int main()
{
    multiset<int> my_set = {1,2,3};
    multiset<int>::iterator itr1;


    //set have dedicated find() function as well, because it has RN of O(log n)
    cout<<"Find related:"<<endl;
    multiset<int>::iterator itr2 = my_set.find(34);
    cout<<*itr2<<endl;

    //insert demo
    cout<<"Insert related:"<<endl;
    pair<multiset<int>::iterator, bool> ret;
    multiset<int>::iterator ret1;
    ret1 = my_set.insert(4);
    cout<<*ret1<<endl;

    //when trying to insert duplicate element
    ret1 = my_set.insert(2);
    cout<<*ret1<<endl;

    //erase element from the set (None of Sequence container allows this kind of erase)
    multiset<int>::iterator it = my_set.begin();
    my_set.erase(it);   //removes first element from the set
    my_set.erase(3);    //removes element 3 from the set

    //let's traverse set
    for(int i: my_set){
        cout<<i<<" ";
    }
    return 0;
}
