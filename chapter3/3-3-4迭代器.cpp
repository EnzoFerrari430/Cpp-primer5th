#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <typeinfo>
using namespace std;
int main()
{
    /*
        ��ָ�벻һ�����ǣ���ȡ����������ʹ��ȡ��ַ�����е�����������ͬʱӵ�з��ص������ĳ�Ա��
        ���磬��Щ���Ա��ӵ����Ϊbegin��end�ĳ�Ա������begin��Ա���𷵻�ָ���һ��Ԫ�صĵ�������
        b��ʾv�ĵ�һ��Ԫ�أ�e��ʾβԪ�ص���һ��λ��
        auto b = v.begin(),e = v.end();

    */
    string s("some string");
    //�ж�s�Ƿ��ǿ�
    if(s.begin() != s.end())
    {
        auto it = s.begin();
        *it = toupper(*it);
    }
    cout<<s<<endl;
    /*
        ��if�ڲ�����һ������������it����begin���صĽ���������������͵õ�ָʾs�еĵ�һ���ַ��ĵ�����,������ͨ���������������һ���ַ�����Ϊ
        ��д��ʽ
    */

    //�ѵ�һ�����ʸ�Ϊ��д
    string str;
    getline(cin,str);
    for(auto it = str.begin();it!= str.end() && !isspace(*it);it++)
    {
        *it = toupper(*it);
    }
    cout<<str<<endl;
    vector<int> v;
    const vector<int> cv;
    auto it = v.begin();  //vector<int>::iterator
    auto it2 = cv.begin();//vector<int>::const_iterator
    cout<<typeid(it).name()<<endl;
    cout<<typeid(it2).name()<<endl;
    //const int num;
    //�������ֻ��������д�����Ļ������const_iterator���ͣ��õ�const_iterator����C++11��׼����2���º���cbegin��cend
    auto it3 = v.cbegin();//vector<int>::const_iterator
    cout<<typeid(it3).name()<<endl;
    return 0;
}
