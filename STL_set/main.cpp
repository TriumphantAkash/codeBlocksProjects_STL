#include <iostream>
#include<set>
using namespace std;

int main()
{
    set<int> my_set = {1,2,3};
    set<int>::iterator itr1;


    //set have dedicated find() function as well, because it has RN of O(log n)
    cout<<"Find related:"<<endl;
    set<int>::iterator itr2 = my_set.find(34);
    if(itr2 == my_set.end()){
        cout<<"element not present"<<endl;
    }

    //insert demo
    cout<<"Insert related:"<<endl;
    pair<set<int>::iterator, bool> ret;
    ret = my_set.insert(4); //set insert() function returns a pair of (iterator and bool)
    cout<<*ret.first<<endl; //points to 4
    cout<<ret.second<<endl; //true, because correctly inserted (no duplicate)

    //when trying to insert duplicate element
    ret = my_set.insert(2);
    cout<<*(ret.first)<<endl;   //points to old 2
    cout<<ret.second<<endl;     //false because trying to insert duplicate element

    //erase element from the set (None of Sequence container allows this kind of erase)
    set<int>::iterator it = my_set.begin();
    my_set.erase(it);   //removes first element from the set
    my_set.erase(3);    //removes element 3 from the set

    //let's traverse set
    for(int i: my_set){
        cout<<i<<" ";
    }
    return 0;
}
