#include <iostream>

using namespace std;

class ABC{
    public:
    int a;
    char b;
};

std::ostream &operator<<(std::ostream &os, ABC const &m) {
    return os << m.a;
}

int main()
{
    ABC abc;
    abc.a = 10;
    abc.b = 'a';

    cout<<abc<<endl;
   // cout<<(abc.a)*10<<endl;


    return 0;
}
