#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

/*
����˼�� unique_ptr��ʾ��ĳ��ʱ��ֻ����һ��unique_ptrָ��һ�������Ķ��󡣵�unique_ptr������ʱ������ָ�Ķ���Ҳ�����١�
��shared_ptr��ͬ��û�����Ƶ�make_shared�ı�׼�⺯������һ��unique_ptr��
��Ϊһ��unique_ptrӵ����ָ��Ķ������unique_ptr��֧����ͨ�Ŀ�����ֵ����


u.release()     u������ָ��Ŀ���Ȩ������ָ�룬����u�ÿ�

u.reset()       �ͷ�uָ��Ķ���

u.reset(p)      ����ṩ������ָ��q����uָ��������󣻷���u�ÿ�

u.reset(nullptr)


*/
int main()
{
    unique_ptr<string> p1(new string("Stegosaurus"));
    //unique_ptr<string> p2(p1);  //��֧�ֿ���
    //unique_ptr<string> p3;
    //p3 = p2;  //��֧�ָ�ֵ

    //��Ȼ���ܿ�����ֵunique_ptr��������ͨ������release��reset��ָ�������Ȩ��һ������const��unique_ptrת�Ƹ���һ��unique_ptr
    unique_ptr<string> p2(p1.release());  //release��p1�ÿ�
    unique_ptr<string> p3(new string("Trex"));
    p2.reset(p3.release());  //reset�ͷ���ԭ�����ڴ�

    //p2.release();     ����p2�����ͷ��ڴ棬�������Ƕ�ʧ��ָ��
    auto p = p2.release();  //��ȷ������Ҫ�ǵ�delete(p)



    return 0;
}
