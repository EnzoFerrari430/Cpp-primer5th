#include <iostream>
using namespace std;

/*
    Ĭ������£�����һ��ֵ�������ı�����lambda����ı���ֵ���������ϣ���ܸı�һ��������ı�����ֵ��
    �ͱ����ڲ����б��׼��Ϲؼ���mutable(���Ǹ��ڲ����б����)
*/

void fcn3()
{
    size_t v1 = 42;  //�ֲ�����
    //f���Ըı���������ı�����ֵ
    auto f = [v1]()mutable{return ++v1;};
    v1 = 0;
    cout<<f()<<endl;
}

//һ����const���͵ı������������ò������޸�����ֵ
void fcn4()
{
    size_t v1 = 42;
    //v1��һ����const����������
    //����ͨ��f2�е����øı���
    auto f2 = [&v1]{return ++v1;};
    v1 = 0;
    cout<<f2()<<endl;
}


int main()
{
    fcn3();
    fcn4();
    return 0;
}
