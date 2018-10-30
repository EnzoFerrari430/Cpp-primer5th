#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> s1{"hello world","c++"};
    vector<string>::iterator iter;
    iter = s1.begin();
    cout<<*iter++<<endl;
    //cout<<(*iter)++<<endl; *iter类型是string  ++操作没有意义
    cout<<(*iter).empty()<<endl;
    cout<<iter->empty()<<endl;
    //cout<<*++iter<<endl;
    cout<<iter++->empty()<<endl;





    return 0;
}
