#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
    ����������˺������÷��������ǿ�����ʹ�ú���һ��ʹ�øö�����Ϊ��������ͬʱҲ�ܴ洢״̬����������ͨ����������Ǹ������

    ����ඨ���˵���������������Ķ��������������
*/

struct absInt
{
    int operator()(int val)const{
        return val < 0? -val : val;
    }
};

/*
    �������������operator()֮��Ҳ���԰���������Ա
    ��Щ��Աһ�㱻���ڶ��Ƶ���������еĲ���
*/

class PrintString
{
public:
    PrintString(ostream &o = cout,char c = ' '):os(o),sep(c){}

    void operator()(const std::string &s) const {os<< s <<sep;}
private:
    ostream &os;  //����д���Ŀ����
    char sep;  //���ڽ���ͬ����������ַ�

};




int main()
{
    int i = -42;
    absInt absObj;
    int ui = absObj(i);
    cout<<ui<<endl;

    vector<string> vs = {"C","C++","java","python","go","ruby"};
    for_each(vs.begin(),vs.end(),PrintString(cerr,'\n'));



    return 0;
}
