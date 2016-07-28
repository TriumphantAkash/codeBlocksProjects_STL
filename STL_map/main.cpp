/*
--> Associative containers are typically implemented with binary tree --> The Key attribute of associative containers is that they are always sorted So, when you insert an element, it gets inserted at right position and when you delete an element from them, it makes sure it is sorted after delete oprtn

--> push_back(), push_front() does not make sense then.

--> The world 'associative' in the associative containers comes from the MAPS, where key is associated with a value
*/


/*
--> As we know that associative containers are typically implemented with binary tee
and are always sorted.

--> However, sometime people don't want to sort them according to their value, they want to sort them according to a key.
So we have a key and value pair

--> This is why we have map/multimap

--> Map/Multimap have exactly the same interface as set/multiset EXCEPT the fact that
EACH ELEMENT IN A MAP/MULTIMAP IS A PAIR<FIRST, SECOND>, RATHER THEN A SINgLE VALUE (LIKE IN SET/MULTISET)
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> my_map;

    //insert
    my_map.insert(pair<string,int>("Akash", 100));
    my_map.insert(pair<string,int>("Chaturvedi", 200));
    my_map.insert(pair<string,int>("Ashesh", 300));

    //traverse
    for(pair<string, int> traverse_pair:my_map){
        cout<<traverse_pair.first<<" "<<traverse_pair.second<<endl;
    }
     cout<<endl;

    //another traverse
    map<string, int>::iterator itrr = my_map.begin();
    while(itrr != my_map.end()){
        cout<<(*itrr).first<<"=>"<<(*itrr).second<<endl;
        itrr++;
    }
    cout<<endl;

    //find (REMEMBER: it returns an iterator pointing to the whole pair)
    map<string, int>::iterator i = my_map.find("Chaturvedi");
    cout<<(*i).first<<" "<<(*i).second<<endl;
    return 0;
}
