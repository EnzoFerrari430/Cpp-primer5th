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


    auto it = std::find_if_not(vi.begin(),vi.end(),std::bind(std::modulus<int>(),n,_2 ) );  //find_if_not 搜索对谓词返回 false 的元素，这里谓词返回0代表被整除

    //如果到达末尾
//    if( vi.end() == it )
//    {
//
//    }

    return 0;
}
