#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <iterator>  //�����������begin ��end����
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
int main()
{
    string nums[] = {"one","two","three"};
    string *p = &nums[0];

    //�������ԣ��ܶ��õ��������ֵĵط��������������Զ��Ľ����������滻��һ��ָ��������Ԫ�ص�ָ��
    string *p2 = nums;

    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    auto ia2(ia);
    decltype(ia) ia3;
    //cout<<typeid(ia2).name()<<endl;  Pi����ָ��  ��Ϊia�൱�� &ia[0]
    //cout<<typeid(ia3).name()<<endl;  A10_i  10���������ɵ�����

    //����ʹ�õ����������ָ������Ԫ�ص�ָ����ǰ�ƶ�����һ��λ����
    int *ptr = ia;
    ptr++;
    cout<<*ptr<<endl;

    //����ĵ�����ʹ�ã��������Ԫ��ָ��õõ���βԪ��ָ���ָ��βԪ�ص���һλ��ָ��
    int *b = ia;  //��Ԫ��ָ��
    int *e = &ia[10];  //ia��10��Ԫ�أ�βԪ�ص�������9������βԪ�ص���һλָ�����10
    for(b = ia;b!=e;b++)
    {
        cout<<*b<<" ";
    }
    cout<<endl;

    //��Ȼ���淽�����ԣ�����Ҫ����β��ָ�룬���׳���C++11�±�׼����2����Ϊbegin��end�ĺ�������2�������������еĺ���
    //�������ƣ������鲻�������ͣ���2���������ܵ���Ա������ֻ�ܰ����鵱�����ǵĲ���
    int *beg = begin(ia);  //��Ԫ��ָ��
    int *last = end(ia);   //β��ָ��




    return 0;
}
