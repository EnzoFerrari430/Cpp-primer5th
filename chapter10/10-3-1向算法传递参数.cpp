#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
    单词按长度排序，大小一样的再按字典序排序
    为了按长度重排vector，我们使用sort的第二个版本，它接受第三个参数，一个谓词

    第三个参数是排序的方法，可以是从大到小也可是从小到大，还可以不写第三个参数，此时默认的排序方法是从小到大排序。

*/
//比较函数，用按长度排序单词
bool isShort(const string &s1,const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    string s1 = "kill";
    string s2 = "will";
    cout<< ( s1 < s2 ) <<endl;
    string str;
    vector<string> vec;
    while(cin>>str)
    {
        vec.push_back(str);
    }
    //sort(vec.begin(),vec.end(),isShort);

    //带有stable的函数可保证相等元素的原本相对次序在排序后保持不变
    //"summer" 和 "winter" 就是相等的，如果在"summer" 出现在"winter"前面，用带stable的函数排序后，他们的次序一定不变，
    //如果你使用的是不带"stable"的函数排序，那么排序完 后，"winter"有可能在"summer"的前面。
    stable_sort(vec.begin(),vec.end(),isShort);

    for(auto c: vec)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    return 0;
}
