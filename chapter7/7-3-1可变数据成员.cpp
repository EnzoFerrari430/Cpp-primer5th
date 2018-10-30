#include <iostream>
#include <string>
using namespace std;

class Screen
{
public:
    void some_member() const;  //this指针默认是指向类类型非常量版本的常量指针  Screen *const
    Screen(): access_ctr(0)
    {

    }
private:
    mutable size_t access_ctr;

};

void Screen::some_member() const
{
    ++access_ctr;
}

int main()
{
    Screen item;
    item.some_member();



    return 0;
}
