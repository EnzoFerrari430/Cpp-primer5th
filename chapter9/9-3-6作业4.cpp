#include <iostream>
#include <vector>
using namespace std;
//9.34  ��һ�������ͻ�����ѭ��
int main()
{
    vector<int> vi{1,2,2,2,2,2,2};
    auto iter = vi.begin();
    while(iter != vi.end())
    {
        if(*iter % 2)
            iter = vi.insert(iter,*iter);  //�����λ����iter֮ǰ��Ȼ�󷵻���Ԫ�صĵ����������Դ�ʱ�ĵ�������ԭ��λ�õ�ǰһλ��������ѭ��
        ++iter;
    }
    for(auto c : vi)
        cout<<c<<' ';
    cout<<endl;


    return 0;
}
