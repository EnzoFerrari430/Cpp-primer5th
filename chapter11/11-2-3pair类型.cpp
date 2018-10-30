#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>  //pair所在头文件
#include <algorithm>
using namespace std;
//创建一个pair对象的函数
pair<string,int> process(vector<string> &v)
{
    //处理v
    //v.back() v.front() 返回v的末尾元素和起始元素的引用
    if( !v.empty() )
    {
        return {v.back(),v.back().size()};  //列表初始化
        //也可以用make_pair来生成对象
        //return make_pair(v.back(),v.back().size() );
    }
    else
    {
        return pair<string,int>();  //隐式构造返回值
    }
}
int main()
{
    vector<int> vec{0,1,2,3,4,5,6,7,8,9};
    cout<<vec.back()<<endl;

    return 0;
}
