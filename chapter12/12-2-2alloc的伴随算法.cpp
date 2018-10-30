#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
/*
��Щ�����ڸ���Ŀ��λ�ô���Ԫ�أ���������ϵͳ�����ڴ������
uninitialized_copy(b,e,b2)      �ӵ�����b��eָ�������뷶Χ�п���Ԫ�ص�������b2ָ����δ�����ԭʼ�ڴ��С�b2ָ����ڴ�����㹻��
                                �ܹ���������������Ԫ�صĿ���,����һ��β�������
uninitialized_copy_n(b,n,b2)    �ӵ�����bָ���Ԫ�ؿ�ʼ������n��Ԫ�ص�b2��ʼ���ڴ���

uninitialized_fill(b,e,t)       �ڵ�����b��eָ����ԭʼ�ڴ淶Χ�д������󣬶����ֵ��Ϊt�Ŀ���

uninitialized_fill_n(b,n,t)     �ӵ�����bָ����ڴ��ַ��ʼ����n������b����ָ���㹻���δ�����ԭʼ�ڴ棬�ܹ����ɸ��������Ķ���
                                ����һ��β�������
*/
int main()
{
    allocator<int> alloc;
    vector<int> v1{1,2,3,4,5,6};
    auto p = alloc.allocate(v1.size() * 2);
    //ͨ������v1�е�Ԫ���������p��ʼ��Ԫ��
    auto q = uninitialized_copy(v1.begin(),v1.end(),p);
    //��ʣ��Ԫ�س�ʼ��Ϊ42
   uninitialized_fill_n(q,v1.size(),42);
    while(p != q+6)
    {
        cout<<*p<<" ";
        ++p;
    }
    cout<<endl;


    return 0;
}
