#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;
int main()
{
    vector<int> vi{2,3};
    int n;
    cin>>n;


    auto it = std::find_if_not(vi.begin(),vi.end(),std::bind(std::modulus<int>(),n,_2 ) );  //find_if_not ������ν�ʷ��� false ��Ԫ�أ�����ν�ʷ���0��������

    //�������ĩβ
//    if( vi.end() == it )
//    {
//
//    }

    return 0;
}
