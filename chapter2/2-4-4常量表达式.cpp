#include <iostream>

/*
    �������ʽ��ֵָ����ı�����ڱ�������о��ܵõ��������ı��ʽ
    ����ֵ�����ڳ������ʽ,�ó������ʽ��ʼ����const����Ҳ�ǳ������ʽ

*/

int main()
{
    //�����ǲ��ǳ������ʽ�������������ͺͳ�ʼֵ����
    const int max_files = 20;  //max_files�ǳ������ʽ
    const int limit  = max_files + 1;  //limit�ǳ������ʽ
    int staff_size = 27;  //staff_size���ǳ������ʽ  ��ʼֵ��һ������ֵ�����������Ͳ���const int
    //const int sz = get_size();  ���ǳ������ʽ


    //C++11��׼   ����Ϊconstexpr�ı���һ����һ�����������ұ����ó������ʽ��ʼ��
    constexpr int mf = 20;  //
    constexpr int li = mf + 1;
    //constexpr int sz = size();  ֻ�е�size()��һ��constexpr����ʱ����һ����ȷ�����

    //constexpr��ָ���ʼֵ������nullptr ��0�������Ǵ洢��һ���̶���ַ�еĶ���
    const int *p = nullptr;  //ָ�����ͳ�����ָ��
    constexpr int *q = nullptr;  //����ָ��  constexpr�Ѷ���Ķ�����Ϊ�� ����const

    int null = 0,*p1 = &null;

    return 0;
}
