#include <iostream>
using namespace std;

class Debug
{
public:
    constexpr Debug(bool b = true):hw(b),io(b),other(b){}  //constexpr�����ĺ����� ֻ��ӵ��һ��return���,�빹�캯���Ĳ�����return��ϣ�����
    constexpr Debug(bool h,bool i,bool o):hw(h),io(i),other(o){}  //������ֻ��Ϊ��

    constexpr bool any(){return hw || io || other;}

    void set_io(bool b){io = b;}
    void set_hw(bool b){hw = b;}
    void set_other(bool b){hw = b;}
private:
    bool hw;  //Ӳ������
    bool io;  //IO����
    bool other;  //��������
};


//7.54 �����ԣ�constexpr������ֻ����return���

int main()
{


    return 0;
}
