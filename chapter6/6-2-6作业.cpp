#include <iostream>
#include <initializer_list>
using namespace std;
int add(initializer_list<int> vi)
{
    int sum = 0;
    for( auto ib = vi.begin() ; ib != vi.end(); ++ib)
        sum += *ib;
    return sum;
}
int main()
{
    //���Ҫ��initializer_list�β��д���һ��ֵ�����У����������з���һ�Ի�������
    cout<<add({1,2,3,4,5,6});

    //6.28 elem  const std::string&
    //6.29 ���������Щ�����ô�ֵ�ķ�ʽ(������)�Ƚ����ۣ���Щ���������ñȽ�����
    return 0;
}
