#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
/*
����͸ı�shared_ptr����������
    shared_ptr<T> p(q)
    shared_ptr<T> p(u)
    shared_ptr<T> p(q,d)
    shared_ptr<T> p(p2,d)


    p.reset()
    p.reset(q)
    p.reset(q,d)

*/
int main()
{
    //�������ʼ��һ������ָ�룬���ͻᱻ��ʼ����һ����ָ��
    shared_ptr<double> p1;  //shared_ptr����ָ��һ��double
    shared_ptr<int> p2(new int(42));  //p2ָ��һ��ֵΪ42��int

    //����ָ�����������ָ�빹�캯����explicit�ġ���˲��ܽ�һ������ָ����ʽת��Ϊ����ָ�룬����ʹ��ֱ�ӳ�ʼ����ʽ������ʼ��һ������ָ��
    //shared_ptr<int> p1 = new int(1024);  ������ = ����ʽת��
    shared_ptr<int> p2(new int(1024));  //ֱ�ӳ�ʼ��

    //Ĭ������£�һ��������ʼ������ָ�����ָͨ�����ָ��̬�ڴ棬��Ϊ����ָ��Ĭ��ʹ��delete�ͷ����������Ķ���
    //���ǿ��Խ�����ָ��󶨵�һ��ָ���������͵���Դ��ָ���ϣ����Ǳ����ṩ�Լ��Ĳ�������delete


    return 0;
}
