#include <iostream>
#include <string>
using namespace std;

class Screen
{
public:
    void some_member() const;  //thisָ��Ĭ����ָ�������ͷǳ����汾�ĳ���ָ��  Screen *const
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
