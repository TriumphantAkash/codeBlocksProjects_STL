#include <iostream>

using namespace std;

class ABC{
    public:
    int a;
    char b;
};

int main()
{
    ABC abc;
    abc.a = 10;
    abc.b = 'a';

    cout<<abc.a<<endl;
    cout<<(abc.a)*10<<endl;


    return 0;
}
