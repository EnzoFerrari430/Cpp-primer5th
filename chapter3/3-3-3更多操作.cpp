#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1{1,2,3,4,5,6,7,8,9};
    for(auto &i:v1)
    {
        i *= i;
    }
    for(auto i:v1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    //vector������������ǰ�����Ԫ�ص�����
    //vector<int>::size_type  ��ȷ
    //vector::size_type  ����
    vector<int>::size_type n;
    n = v1.size();
    cout<<n<<endl;




    return 0;
}
