#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<forward_list>
using namespace std;

void func(string &s, string &oldVal, string &newVal)
{
    int _size = oldVal.size();
    string::iterator it1 = s.begin();
    string::iterator it2 = newVal.begin();
    string::iterator it3 = newVal.end();

    for (it1; it1 <= (s.end()-oldVal.size()+1); ++it1)
    {
        //pos��������������������õ�,���ؽ�ȡ����string
        if((s.substr(it1-s.begin(),_size) == oldVal))//substr()�����þ��ǽ�ȡstring�е�һ��
        {
            it1 = s.erase(it1,it1+_size);//���ص������һ����ɾ����Ԫ��֮���λ��
            s.insert(it1, it2,it3);//ԭ������insert()����������ָ���һ�������ַ��ĵ����������ҽ���ֱ�Ӹ�ֵ��it1����constתΪ��const�����Ͳ�ͬ����������
            advance(it1,_size);//��ǰ_size��С��Ŀ����Ϊ����it1��Ȼָ��ǰ�ַ�������λ�ã���Ϊǰ�������++it1
        }
    }
}

int main()
{
    string s = "abcdefg";
    string oldval = "bc";
    string newval = "asas";
    func(s,oldval,newval);
    cout<<s<<endl;
    return 0;
}
