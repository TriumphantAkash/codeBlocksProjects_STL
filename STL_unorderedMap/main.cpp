//ASSOCIATIVE ARRAY is implemented using unordered_map

#include <iostream>
#include<unordered_map>

using namespace std;

int main()
{
    unordered_map<char, string> my_u_map;
    my_u_map.insert(pair<char, string>('M', "Monday"));
    my_u_map.insert(pair<char, string>('T', "Tuesday"));
    my_u_map.insert(pair<char, string>('W', "Wednesday"));
    my_u_map.insert(pair<char, string>('F', "Friday"));
    my_u_map.insert(pair<char, string>('S', "Saturday"));
    my_u_map['s'] = "Sunday";   //another way to insert

    //Traverse
    cout<<"Traversing the map"<<endl;
    for(pair<char, string> element_pair:my_u_map){
        cout<<element_pair.first<<"=>"<<element_pair.second<<endl;
    }

    //find function
    cout<<"Find demo"<<endl;
    unordered_map<char, string>::iterator i = my_u_map.find('s');
    cout<<(*i).second<<endl;
    return 0;
}
