#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    /*
    ֪ʶ�㣺vector�ĳ�ʼ����
1�����ò����Գ�Ϊvector��Ԫ�أ���Ϊ�䲻�Ƕ���
2�������û����ų�ʼ��ÿһ��ֵ��
3������������ָ��Ԫ�ظ�������ͬ��Ԫ��ֵ��
4��ֻ��ʹ��ֱ�ӳ�ʼ����������ʹ�ÿ�����ʼ����vector֮��Ŀ����ǿ��еģ���Ҫ��֤������ͬ��
    */
    vector<vector<int>> ivec;
    //vector<string> svec = ivec;
    vector<string> svec(10,"NULL");

    vector<int> v1;              //��vector
    vector<int> v2(10);          //10��Ԫ�أ�ֵΪ0
    vector<int> v3(10,42);       //10��Ԫ�أ�ֵΪ42
    vector<int> v4{10};          //1��Ԫ�أ�ֵΪ10
    vector<int> v5{10,42};       //2��Ԫ�أ�ֵΪ10,42
    vector<string> v6{10};       //10��Ԫ�أ����ǿ��ַ���
    vector<string> v7{10,"hi"};  //10��Ԫ�أ�����"hi"

    for(auto c:v7)
    {
        cout<<c<<" ";
    }



    return 0;
}
