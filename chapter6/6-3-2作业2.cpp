#include <iostream>
using namespace std;

//bingo ����һ���������õĺ����õ���ֵ�����򱨴�
int &get(int *arry,int index)
{
    return arry[index];
}

int main()
{
    int ia[10];
    int i;
    for(i = 0; i != 10; ++i)
    {
        get(ia,i) = i;
    }
    for(i = 0;i!= 10; ++i)
    {
        cout<<ia[i]<<' ';
    }
    return 0;
}
