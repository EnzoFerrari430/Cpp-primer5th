#include <iostream>
#include <typeinfo>
using namespace std;

/*
    ����һ������Ϊauto������ʱ����ʼֵ�еĶ��㳣��������Ȼ������
    ������һ����������Ǹ���ʼֵ��һ�����ã����ʱ�ĳ����Ͳ��Ƕ��㳣����

*/
int main()
{
    /*
    const int i = 42,&r = i;
    auto num = r;
    cout<<typeid(r).name()<<endl;
    cout<<typeid(num).name()<<endl;
    */
    int i = 0,&r = i;
    const int ci = i;
    auto k = ci,&l = i;  //k��int l��int������
    auto &m = ci,*p = &ci;
    //auto &n = i,*p2 = &ci;  i��int p2��pki
    cout<<typeid(m).name()<<endl;  //i
    cout<<typeid(p).name()<<endl;  //pki
    cout<<typeid(*p).name()<<endl;  //i
    cout<<typeid(p2).name()<<endl;  //pki
    cout<<typeid(*p2).name()<<endl;  //i
    cout<<typeid(&ci).name()<<endl;  //pki



    return 0;
}
