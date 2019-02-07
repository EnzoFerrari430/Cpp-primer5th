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
    auto predicator = [&](int i){return 0 != mod(n,i);};  //捕获列表 & 表示函数体内可以使用lambda所在作用范围内所有可见的局部变量，并且是引用的方式，
    auto is_divisible = std::any_of(vi.begin(),vi.end(),predicator);  //找到一个就返回true,都找不到返回false
    cout<< (is_divisible ? "No!":"Yes!")<<endl;
    return 0;
}
