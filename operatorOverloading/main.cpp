#include <iostream>
#include <string.h>
//using namespace std;


class string {
    public:
    char *s;
    int size;
    void getstring(char *str)
    {
        size = strlen(str);
        s = new char[size];
        strcpy(s,str);
        std::cout<<s<<std::endl;
    }

    void operator+(string ob){
        std::cout<<"current s is:"<<s<<std::endl;
       // std::cout<<"passed string is:"<<ob<<std::endl;
        size = size+ob.size;
        std::cout<<"new size is:"<<size<<std::endl;
        //s = new char[size+5];
        strcat(s,ob.s);
        std::cout<<"\nConcatnated String is: "<<s;
    }

     bool operator==(string ob){
        if(strcmp(s, ob.s) == 0){
            return true;
        }else{
            return false;
        }
    }

    void operator=(string ob){
        std::cout<<"current s is:"<<s<<std::endl;
       // std::cout<<"passed string is:"<<ob<<std::endl;
        size = std::max(size,ob.size);
        std::cout<<"new size is:"<<size<<std::endl;
        s = new char[size+1];
        strcpy(s,ob.s);
    }

};

int main()
{
    string ob1, ob2;
    char string1[10], string2[10];

    std::cout<<"\nEnter First String:";
    std::cin>>string1;

    ob1.getstring(string1);

    std::cout<<"\nEnter Second String:";
    std::cin>>string2;

    ob2.getstring(string2);

    //Calling + operator to Join/Concatenate strings
    if(ob1 == ob2){
        std::cout<<"equal"<<std::endl;
    }else{
        std::cout<<"unequal"<<std::endl;
    }

    ob1 = ob2;
    std::cout<<"now first string is: "<<ob1.s<<std::endl;
    return 0;
}
