#include <iostream>
#include <vector>
#include <list>
using namespace std;
/*
    ˳������(��array��)��������һ����Ϊassign�ĳ�Ա���������Ǵ�һ����ͬ�����ݵ����͸�ֵ�����ߴ�������һ�������и�ֵ��
    assign�����ò�����ָ����Ԫ��(�Ŀ���)�滻��������е�����Ԫ��
*/
int main()
{
    list<string> names;
    vector<const char *> oldstyle;
    //names = oldstyle;  //error  ���������Ͳ�ƥ��

    //��const char *ת��Ϊstring
    names.assign(oldstyle.cbegin(),oldstyle.cend());
    //assign�ĵ��ý�names�е�Ԫ���滻Ϊ������ָ����Χ�е�Ԫ�صĿ�����assign�Ĳ����������������ж��ٸ�Ԫ���Լ����ǵ�ֵ����ʲô
    //��ע�⣡��  ���ھɵ�Ԫ�ر��滻����˴��ݸ�assign�ĵ���������ָ�����assign������

    return 0;
}
