#include <iostream>
#include <string>
#include <memory>
using namespace std;

/*
weak_ptr��һ�ֲ�������ָ����������ڵ�����ָ�룬��ָ��һ����shared_ptr����Ķ���
��һ��weak_ptr�󶨵�һ��shared_ptr����ı�shared_ptr�����ü���.
һ�����һ��ָ������shared_ptr�����٣�����ͻᱻ�ͷš���ʹ��weak_ptrָ�����

weak_ptr<T> w
weak_ptr<T> w(sp)

w = p;

w.reset();

w.use_count();

w.expired()

w.lock()

*/
int main()
{
    //����weak_ptrҪ��shared_ptr����ʼ����
    auto p = make_shared<int>(42);
    weak_ptr<int> wp(p);  //wp������p  p�����ü���δ�ı�



    return 0;
}
