#include <iostream>
#include <vector>
using namespace std;

//9.35 capacity��vector�����·����ڴ������� ������ɵ�Ԫ�ش�С size��������Ԫ�صĴ�С
//9.36 �����ܡ�
//9.37 list�������ǲ���ҪԤ�Ȼ�ȡһ���ڴ�ġ� array�����飬�����ʱ���С���Ѿ�ȷ����

//9.38
int main()
{
    int i;
    vector<int> vi;
    cout<<"vi size: "<<vi.size()<<"vi capacity: "<<vi.capacity()<<endl;
    while(cin>>i)
    {
        vi.emplace_back(i);
        cout<<"vi size: "<<vi.size()<<" vi capacity: "<<vi.capacity()<<endl;
    }


    return 0;
}

//9.39
