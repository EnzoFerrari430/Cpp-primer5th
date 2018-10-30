#include <iostream>
#include <vector>
using namespace std;
//9.11
int main()
{
    vector<int> v1{1,2,3,4,5,6};
    vector<int> v2;
    vector<int> v3(v1);
    vector<int> v4 = v1;
    vector<int> v5 = {6,5,4,3,2,1};
    vector<int> v6(v1.begin()+1,v1.end()-1);
    for(auto c:v1)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    for(auto c:v2)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    for(auto c:v3)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    for(auto c:v4)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    for(auto c:v5)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    for(auto c:v6)
    {
        cout<<c<<' ';
    }
    cout<<endl;


    return 0;
}

/*
    9.12
        拷贝赋值：要求2个容器的类型和元素的类型都要相同

        迭代器赋值：不要求容器的类型相同，元素的类型要求可以将复制的元素转换成正在初始化的容器的元素类型

*/




















