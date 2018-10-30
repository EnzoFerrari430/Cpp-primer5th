#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
/*
shared_ptr��unique_ptr��֧�ֵĲ���
    shared_ptr<T> sp    ������ָ�룬ָ��������T�Ķ���
    unique_ptr<T> up

    p                   ��p����һ���ж���������pָ��һ��������Ϊtrue
    *p                  ������p�������ָ��Ķ���
    p->mem              �ȼ���(*p).mem
    p.get()             ����p�б����ָ�룬��С��ʹ�ã�������ָ���ͷ�������󣬷��ص�ָ����ָ��Ķ���Ҳ����ʧ��

    swap(p,q)           ����p��q�е�ָ��
    p.swap(q)

shared_ptr���еĲ���
    make_shared<T>(args)    ����һ��shared_ptr��ָ��һ����̬���������ΪT�Ķ���ʹ��args��ʼ������

    shared_ptr<T>p(q)       p��shared_ptr q�Ŀ������˲��������q�еļ�������q��ָ�������ת��ΪT*

    p = q                   p��q����shared_ptr���������ָ��������໥ת�����˲�����ݼ�p�����ü���������q�����ü�����
                            ��p�����ü�����Ϊ0����������ԭ�ڴ��ͷ�
    p.unique()              ��p.use_count() Ϊ1����true�����򷵻�false

    p.use_count()           ������p������������ָ������������ܺ�������Ҫ���ڵ���

*/
int main()
{
    //make_shared����,���巽ʽ��ģ������ͬ
    //make_shared�������������������͵Ķ���,����������κβ���������ͽ���ֵ��ʼ��

    //ָ��һ��ֵΪ42��int��shared_ptr
    shared_ptr<int> p3 = make_shared<int>(42);
    cout<<p3<<endl;
    cout<<*p3<<endl;

    //ָ��һ��ֵΪ"9999999999"��string
    shared_ptr<string> p4 = make_shared<string>(10,'9');
    cout<<p4<<endl;
    cout<<*p4<<endl;

    //ָ��һ��ֵ��ʼ����int����ֵ��0
    shared_ptr<int> p5 = make_shared<int>();
    cout<<p5<<endl;
    cout<<*p5<<endl;

    //auto������һ������,p6ָ��һ����̬����Ŀ�vector<string>
    auto p6 = make_shared<vector<string>>();


    return 0;
}
