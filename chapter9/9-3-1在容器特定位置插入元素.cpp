#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
using namespace std;
/*
    vector、deque、list和string都支持insert成员
    forward_list提供了特殊了insert成员
*/
int main()
{
    //接受一对迭代器或一个初始化列表的insert版本
    vector<string> v = {"quasi","simba","frollo","scar"};
    list<string> slist;
    slist.insert(slist.begin(),v.end()-2,v.end());
    for(auto c: slist)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    slist.insert(slist.end(),{"these","words","will","go","at","the","end"});
    for(auto c:slist)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    return 0;
}
