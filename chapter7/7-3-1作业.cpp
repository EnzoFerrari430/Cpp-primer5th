#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Screen
{
public:
    using pos = string::size_type;  //string�ĵ�λ����
    Screen() = default;
    Screen(pos ht,pos wd):height(ht),width(wd),contents(ht * wd,' '){}
    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht * wd,c) {}
    char get() const
    {
        return contents[cursor];   //��ʽ����
    }
    inline char get(pos ht,pos wd) const;  //��ʽ����
    Screen &move(pos r,pos c);  //����֮����Ϊ����
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
};

//7.25  �������ͺ�string���Ϳ��Կ����͸�ֵ����

int main()
{


    return 0;
}
