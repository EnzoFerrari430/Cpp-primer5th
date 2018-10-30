#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
int main()
{
    //可以通过insert返回值，在容器中的一个特定位置反复插入元素
    string word;
    list<string> lst;
    auto iter = lst.begin();
    while(cin>>word)
        iter = lst.insert(iter,word);

    for(auto c:lst)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    return 0;
}
