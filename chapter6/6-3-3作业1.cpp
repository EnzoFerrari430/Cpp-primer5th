#include <iostream>
#include <string>
using namespace std;
//��������ָ�����ʽ  type(*function(parameter_list))[dimension]
string (&func(int val))[10];

//6.37
//���ͱ���
typedef string arr[10];
arr *func(int val);

//β�÷�������
auto func(int val) -> string(*)[10];

//decltype
string s1[10];
decltype(s1) *func(int val);


//6.38
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
decltype(odd) &arrPtr(int i)
{
    return (i % 2)? odd : even;
}

int main()
{


    return 0;
}
