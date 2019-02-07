#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>
using namespace std;

class StrVec
{

public:
    StrVec();
    StrVec(const StrVec &);
    StrVec& operator=(const StrVec &);

    StrVec(StrVec &&) noexcept;
    StrVec& operator=(StrVec &&) noexcept;
    StrVec getVec(istream &);  //getVec���ص���һ����ֵ

private:
    int i;
    char *p;
};

int main()
{
    StrVec v1,v2;
    //����v2�Ƿǳ����ģ�����v2Ҫ��ƥ��ǳ����汾�ĸ�ֵ�������Ҳ�����ƶ���ֵ�����������v2��һ����ֵ������v2��ƥ�䣬Ȼ����ȥƥ�䳣���汾�Ŀ�����ֵ�����
    v1 = v2;  //v2����ֵ��ʹ�õ��ǿ�����ֵ

    //����v2�Ƿǳ���������Ҫ��ƥ��ǳ����汾�ĸ�ֵ�����������getVec���ص���һ����ֵ�����÷����ƶ���ֵ���������������������ʹ�õ����ƶ���ֵ�����
    v2 = getVec(cin);  //getVec(cin)��һ����ֵ��ʹ���ƶ���ֵ





    return 0;
}
