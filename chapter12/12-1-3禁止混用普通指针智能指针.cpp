#include <iostream>
#include <vector>
#include <memory>
using namespace std;

void process(shared_ptr<int> ptr)
{
    //ʹ��ptr
}   //ptr�뿪�����򣬱�����
//process�Ĳ����Ǵ�ֵ�ķ�ʽ�����ʵ�λᱻ������ptr�С�����һ��shared_ptr����������ü����������process�У����ü�������Ϊ2
//��process����ʱ��ptr�����ü�����ݼ����������Ϊ0����˵��ֲ�ptr������ʱ��ptrָ����ڴ治�ᱻ�ͷ�



//��Ȼ���ܴ��ݸ�processһ������ָ�룬�����Դ��ݸ���һ����ʱ��shared_ptr�����shared_ptr������ָ����ʽ���죬���ܿ��ܳ���

int main()
{
    shared_ptr<int> p(new int(42));  //���ü���Ϊ1
    process(p);
    int i = *p;
    cout<<i<<endl;

    int *x(new int(1024));
    //process(x);  ���ܽ�int*ת����shared_ptr<int>
    process(shared_ptr<int>(x));  //�Ϸ��������ڴ�ᱻ�ͷ�  ������вű���ʽ���죬���ü���Ϊ1��process����ʱ���ü����ݼ����ڴ汻�ͷ�
    int j = *x;
    cout<<j<<endl;

    //��Ҫ��get��ʼ����һ������ָ���Ϊ����ָ�븳ֵ
    //get������������һ������ָ�룬ָ������ָ�����Ķ���


    return 0;
}
