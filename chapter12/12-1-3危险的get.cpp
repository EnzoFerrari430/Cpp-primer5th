#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

    //��Ҫ��get��ʼ����һ������ָ���Ϊ����ָ�븳ֵ
    //get������������һ������ָ�룬ָ������ָ�����Ķ���

int main()
{
    shared_ptr<int> p(new int(321321));  //���ü���Ϊ1
    int *q = p.get();  //��ȷ�����ǲ�Ҫ��q�����ָ�뱻�ͷ�
    {
        //δ����:����������shared_ptrָ����ͬ���ڴ�
        shared_ptr<int>(q);
    }  //���������q�����٣���ָ����ڴ汻�ͷ�
    int foo = *p;  //δ����:pָ����ڴ��Ѿ����ͷ�
    cout<<foo<<endl;


    return 0;
}
