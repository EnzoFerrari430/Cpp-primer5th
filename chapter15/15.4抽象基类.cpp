#include <iostream>
using namespace std;
/*
    ���У�����δ������ֱ�Ӽ̳У����麯�������ǳ������


    ������ඨ�����麯��������������������û�У��������麯���ᱻ����һ����ͨ�����Դ���������򵥵ļ̳��˸ú���
*/

class base
{
public:
    virtual fun()const
    {
        cout<<"virtual function in class base"<<endl;
    }
};

class derived : public base
{
public:
    //virtual fun()const;
};

int main()
{
    derived d;
    d.fun();
    base b1;
    base *b2 = &b1;
    b2->fun();
    b2 = &d;
    b2->fun();

    return 0;
}
