#include <iostream>
#include <utility>  //�±�׼��move�������ڵ�ͷ�ļ�
using namespace std;
/*
    ���ǿ���ͨ������һ����Ϊmove���±�׼�⺯������ð󶨵���ֵ�ϵ���ֵ����
*/
int main()
{
    int rr1 = 42;
    int &&rr3 = std::move(rr1);  //rr1����ֵ,ͨ��move�����󶨵���ֵ������
    //����ʹ��֮�󣬳��˶�rr1��ֵ��������֮�⣬����ʹ������
    //�ڵ���move֮�󣬲��ܶ�  �ƺ� Դ����  ��ֵ���κμ���

    // !!!  move����Ҫֱ�ӵ���  std::move  ������move����������ԭ��

    return 0;
}
