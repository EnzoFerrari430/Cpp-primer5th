#include <iostream>
using namespace std;

void print(int (&arr)[10])
{
    for(auto elem : arr)
    {
        cout<<elem<<endl;
    }
}
//��������д��������print�����Ŀ����ԣ�����ֻ�ܽ����������ڴ�СΪ10������
//&arr ���˵����űز�����
//f(int &arr[10])      //wrong ��arr�����������õ�����
//f(int (&arr)[10])    //bingo arr�Ǿ���10���������������������
int main()
{
    int i = 0;
    int j[2] = {0,1};
    int k[10] = {0,1,2,3,4,5,6,7,8,9};
    //print(&i);  //ʵ�β��Ǻ���10������������
    //print(j);   //ʵ�β��Ǻ���10������������
    print(k);


    return 0;
}
