#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //vector<int> vi(10);  �����ȳ�ʼ����10��int Ԫ��0000000000���ټ���num�����000000000012345678910
    vector<int> vi;
    int num;
    for(num = 1;num<=10;num++)
    {
        vi.push_back(num);
    }

    //��ʼ��һ��cָ��vi�ĵ�һ��Ԫ�أ�c�൱��һ��ָ��
    for(auto c = vi.begin();c!= vi.end(); c++)
    {
        *c = 2*(*c);
        cout<<*c<<" ";
    }



    return 0;
}
