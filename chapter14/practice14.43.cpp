#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;
int main()
{
    vector<int> vi{2,3};
    int n,p;
    cin>>n;
//    bool flag = true;
//    for( auto &c : vi)
//    {
//        auto res = modulus<int>(n,c);
//        if(res)
//        {
//            flag = false;
//            break;
//        }
//    }
//    cout<<flag<<endl;
    std::modulus<int> mod;
    auto predicator = [&](int i){return 0 != mod(n,i);};  //�����б� & ��ʾ�������ڿ���ʹ��lambda�������÷�Χ�����пɼ��ľֲ����������������õķ�ʽ��
    auto is_divisible = std::any_of(vi.begin(),vi.end(),predicator);  //�ҵ�һ���ͷ���true,���Ҳ�������false
    cout<< (is_divisible ? "No!":"Yes!")<<endl;
    return 0;
}
