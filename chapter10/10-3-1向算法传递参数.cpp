#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
    ���ʰ��������򣬴�Сһ�����ٰ��ֵ�������
    Ϊ�˰���������vector������ʹ��sort�ĵڶ����汾�������ܵ�����������һ��ν��

    ����������������ķ����������ǴӴ�СҲ���Ǵ�С���󣬻����Բ�д��������������ʱĬ�ϵ����򷽷��Ǵ�С��������

*/
//�ȽϺ������ð��������򵥴�
bool isShort(const string &s1,const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    string s1 = "kill";
    string s2 = "will";
    cout<< ( s1 < s2 ) <<endl;
    string str;
    vector<string> vec;
    while(cin>>str)
    {
        vec.push_back(str);
    }
    //sort(vec.begin(),vec.end(),isShort);

    //����stable�ĺ����ɱ�֤���Ԫ�ص�ԭ����Դ���������󱣳ֲ���
    //"summer" �� "winter" ������ȵģ������"summer" ������"winter"ǰ�棬�ô�stable�ĺ�����������ǵĴ���һ�����䣬
    //�����ʹ�õ��ǲ���"stable"�ĺ���������ô������ ��"winter"�п�����"summer"��ǰ�档
    stable_sort(vec.begin(),vec.end(),isShort);

    for(auto c: vec)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    return 0;
}
