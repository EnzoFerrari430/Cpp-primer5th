#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int num;
    string str;
    //cin>>str;
    vector<string> s1;
    vector<int> s2;
    //s1.push_back(str);
    while(cin>>num)
    {
        s2.push_back(num);
    }
    auto it = s1.begin();
    auto it2 = s2.begin();
    cout<<(*it2)<<endl;
    //��ͷ����� �ѽ����úͳ�Ա�������������������һ��,���������ݽṹ
    /*
        ĳЩ��vector����Ĳ�����ʹ������ʧЧ
        1.�����ٷ�Χforѭ������vector�������Ԫ��
        2.�κ�һ�ֿ��ܸı�vector���������Ĳ���������push_back������ʹ��vector����ĵ�����ʧЧ

    */



    return 0;
}
