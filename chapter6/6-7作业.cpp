#include <iostream>
#include <string>
#include <vector>
using namespace std;

//6.54
int f(int ,int );
//��һ��vector�������һ��������ָ�룬��ôvector�����ͼ�Ϊ������ָ��
vector<int (*)(int,int)> p;

//6.55
int add(int a1,int a2)
{
    return a1 + a2;
}

int multi(int a1,int a2)
{
    return a1 * a2;
}

int mns(int a1,int a2)
{
    return a1 - a2;
}

int dvs(int a1,int a2)
{
    return ( a2 == 0? 0:a1 / a2);
}

int main()
{
    p.push_back(add);
    p.push_back(mns);
    p.push_back(multi);
    p.push_back(dvs);

    for(auto c:p)  //c����ÿ�������ĵ�ַ
        cout<<c(5,3)<<' ';

    return 0;
}
