#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};
    auto beg = vi.begin();
    while(beg != vi.end())
    {
        ++beg;
        //���뱣֤ÿ�θı������Ĳ���֮����ȷ�����¶�λ������.��vector��string��deque��Ϊ��Ҫ
        beg = vi.insert(beg,42);  //��begָ���Ԫ��֮ǰ����һ��ֵΪt��Ԫ�أ�����ָ�������Ԫ�صĵ�����
        ++beg;
    }

    for(auto c: vi)
        cout<<c<<' ';
    cout<<endl;


    return 0;
}
