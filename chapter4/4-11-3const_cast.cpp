#include <iostream>
using namespace std;
int main()
{

    int const i = 10;
    const int *p = &i;
    //int modifier = i;  ����ͨ��������û������

    //int *modifier = &i;  ���ܽ�const int *ת����int *   ����C�����п���ʵ��

    //int &modifier = i;  ������const int ��ʼ��int &
    int *modifier = const_cast<int *>(p);  //ȥ����const����

    *modifier = 7;
    cout<< "i: "<<i<<endl;
    cout<< "p: "<<*p<<endl;
    cout<< "modifier: "<<*modifier<<endl;

    //��ַ
    cout<< "i: "<<&i<<endl;
    cout<< "p: "<<p<<endl;
    cout<< "modifier: "<<modifier<<endl;

    //��ַ���䣬*modifier = 7;δ������Ϊ��Undefined Behavior������δ������Ϊ����������������Ҫ���ľ��Ǳ��������������䡣

    //ԭ���ǣ����ǿ��ܵ�����һ����������const�ĺ�����������Ҫ����ȥ��ʵ�ʲ���ȷʵconst�ģ���������֪����������ǲ���Բ������޸ĵġ�
    //�������Ǿ���Ҫʹ��const_castȥ��const�޶����Ա㺯���ܹ��������ʵ�ʲ�����
    return 0;
}
