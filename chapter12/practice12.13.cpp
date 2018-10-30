#include <iostream>
#include <string>
#include <memory>
using namespace std;
int main()
{
    {
        auto sp = make_shared<int>();
        auto p = sp.get();
        delete p;
    }
    //runtime error:  double free
    return 0;
}
