#include <iostream>
#include <memory>  //������shared_ptr unique_ptr weak_ptr
#include <string>
#include <list>
using namespace std;
/*
    ����vector������ָ��Ҳ��ģ��,��Ҫ�ڼ������и���ָ�����ָ�������
*/
int main()
{
    shared_ptr<string> p1;      //����ָ��string
    shared_ptr<list<int>> p2;   //����ָ��int��list

    if(p1)
    {
        cout<<"p1ָ�벻Ϊ��"<<endl;
        if(p1->empty())
        {
            cout<<"p1ָ��ָ��Ϊ��"<<endl;
        }
    }
    else
    {
        cout<<"p1ָ��Ϊ��"<<endl;
    }

    return 0;
}
