/*

    ���㣺
        ��������ת��Ŀ��Ϊ�������͵Ķ�������ת��

        ���������Եĸ���ԭ������������ı�׼����ת������һ�¡�
        ��ʹ���û����������ת��ʱ�����ת�����Ͱ�����׼����ת�������׼����ת���ļ��𽫾���������ѡ����ѵ�ƥ�����
*/
#include <iostream>
using namespace std;

struct LongDouble
{
    LongDouble(double = 0.0);
    operator double();
    operator float();
};

LongDouble ldObj;
int ex1 = ldObj;  //������������ԣ�double��float������ת�����������һ����
float ex2 = ldObj;  //���ʹ��float������ת����������ȼ���

int main()
{


    return 0;
}
