#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
/*
������С�Ĺ������
    shrink_to_fitֻ������vector��string��deque
    capacity��reserveֻ������vector��string
    c.shrink_to_fit()   �뽫capacity()����Ϊ��size()��ͬ��С
    c.capacity()        �����·����ڴ�ռ�Ļ���c���Ա������Ԫ��
    c.reserve(n)        ��������������n��Ԫ�ص��ڴ�ռ�

    ֻ�е���Ҫ���ڴ�ռ䳬����ǰ����ʱ��reserve���òŻ�ı�vector������
    ��������С���ڵ�ǰ������reserve���ٷ���������һ������ڴ�ռ�
    ��������СС�ڻ���ڵ�ǰ������reserveʲôҲ������С��ʱ���������˻��ڴ�ռ�
*/
int main()
{
    vector<int> ivec;
    cout<<"ivec:size: "<<ivec.size()<<" capacity: "<<ivec.capacity()<<endl;
    for(vector<int>::size_type ix = 0;ix != 24;++ix)
    {
        ivec.push_back(ix);
    }
    cout<<"ivec:size: "<<ivec.size()<<" capacity: "<<ivec.capacity()<<endl;
    ivec.reserve(50);
    cout<<"ivec:size: "<<ivec.size()<<" capacity: "<<ivec.capacity()<<endl;
    //����shrink_to_fitҪ��vector��������ǰ��С�Ķ����ڴ��˻�ϵͳ
    ivec.shrink_to_fit();
    cout<<"ivec:size: "<<ivec.size()<<" capacity: "<<ivec.capacity()<<endl;
    //����shrink_to_fitֻ��һ�����󣬱�׼�Ⲣ����֤�˻��ڴ�
    return 0;
}
