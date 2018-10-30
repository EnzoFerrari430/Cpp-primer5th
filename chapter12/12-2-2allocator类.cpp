#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>
using namespace std;

/*
��׼��allocator�ඨ����ͷ�ļ�memory�У����������ǽ��ڴ����Ͷ�������뿪��



    ��׼��allocator�༰���㷨
allocator<T> a          ������һ����Ϊa��allocator����������Ϊ����ΪT�Ķ������ԭʼ�ڴ�

a.allocate(n)           ����һ��ԭʼ�ģ�δ������ڴ棬����n������ΪT�Ķ���

a.deallocate(p,n)       �ͷŴ�T*ָ��p�е�ַ��ʼ���ڴ棬����ڴ汣����n������ΪT�Ķ���
                        p������һ����ǰ��allocate���ص�ָ�룬��n������p����ʱ��Ҫ��Ĵ�С��
                        �ڵ���deallocate֮ǰ���û������ÿ��������ڴ��д����Ķ������destroy

a.construct(p,args)     p������һ������ΪT*��ָ�룬ָ��һ��ԭʼ�ڴ棺arg�����ݸ�����ΪT�Ĺ��캯����������pָ����ڴ��й���һ������

a.destroy(p)            pΪT*���͵�ָ�룬���㷨��pָ��Ķ���ִ����������


*/
int main()
{
    char *cp = "helloworld";
    allocator<string> alloc;  //���Է���string��allocator����
    auto const p = alloc.allocate(10);  //����10��δ��ʼ����string,���ط�����ڴ���׵�ַ
    auto q = p;
    alloc.construct(q++,10,'c');  //q++֮��  q��ָ���������Ԫ��֮���λ��
    cout<<typeid(p).name()<<endl;
    cout<<q - p<<endl;
    cout<<p<<" "<<q<<endl;
    cout<<*p<<endl;
    //cout<<*q<<endl;
    cout<<cp<<endl;


    //�������������󣬱����ÿ�������Ԫ�ص���destroy���������ǡ�����destroy����һ��ָ�룬��ָ��Ķ���ִ����������
    while(q != p)
    {
        alloc.destroy(--q);
    }

    //�ͷ�����ڴ�
    alloc.deallocate(p,10);


    return 0;
}
