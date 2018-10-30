#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    multimap<string,string> authors = { {"pjd","666"},{"Enzo","C"},{"Enzo","C++"},{"Enzo","Java"},{"Enzo","Python"},{"pp","asdf"} };
    auto pos = authors.find("nn");
    if( pos != authors.end() )
    {
        auto cnt = authors.erase(pos);
        cout<<"删除成功"<<endl;
    }
    else
    {
        cout<<"要删除的元素不存在"<<endl;
    }
    for(const auto &c:authors)
    {
        cout<<c.first<<" "<<c.second<<endl;
    }
    return 0;
}
