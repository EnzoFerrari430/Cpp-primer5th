#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
����������constexpr����ͨ��������ͷ�ļ���,�����ж�����壬���Ǳ�����ȫһ��
    6.43a ����ͷ�ļ��У���Ϊ��inline����
    6.43b ����ͷ�ļ��У���ͨ����Ҳ����ͷ�ļ��бȽϺ�

    6.46 �����ԣ�isShorter�Ĳ���������string���ͣ���������ֵ����

*/
inline bool isShorter(const string &s1,const string &s2)
{
    return s1.size() < s2.size();
}
int main()
{


    return 0;
}
