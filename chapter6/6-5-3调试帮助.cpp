#define NDEBUG  //���������ǰ��
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;


//assert�곣���ڼ��"���ܷ���"������
//assert����Ϊ������һ����ΪNDEBUG��Ԥ���������״̬�����������NDEBUG����assertʲôҲ������Ĭ��״̬��û�ж���NDEBUG����ʱ��ִ������ʱ���
//����NDEBUG�ܱ���������������������ʱ��������Ȼ��ʱ�����Ͳ���ִ������ʱ���.���assertӦ�ý�������֤��Щȷʵ�����ܷ��������顣


void print(const int ia[],size_t size)
{
#ifndef NDEBUG
    //__func__ �Ǳ����������һ���ֲ���̬���������ڴ�ź���������
    cerr<<__func__<<":array size is "<<size<<endl;
#endif // NDEBUG
}
//__func__�����ǰ���Եĺ��������֡�������Ϊÿ�������������� _ _func_ _ ����const char��һ����̬���飬���ڴ�ź�������
//C++���������˶��� _ _func_ _֮�⣬Ԥ������������������4�����ڳ�����Ժ����õ�����
//__FILE__   ����ļ������ַ�������ֵ
//__LINE__   ��ŵ�ǰ�кŵ���������ֵ
//__TIME__   ����ļ�����ʱ����ַ�������ֵ
//__DATE__   ����ļ��������ڵ��ַ�������ֵ


int main()
{
    string s1;
    cin>>s1;
    assert(s1.size() > 10);

    if(s1.size() < 10)
        cerr<<"Error: "<<__FILE__<<" : in function "<<__func__<<" at line "<<__LINE__<<endl<<"      Compiled on "<<__DATE__<<" at "<<__TIME__<<endl<<"     Word read was \""<<s1<<"\": Length too short"<<endl;

    cout<<s1<<endl;



    return 0;
}
