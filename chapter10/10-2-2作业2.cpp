#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
int main()
{
    vector<int> vec;
    list<int> lst;
    int i;
    while(cin>>i)
        lst.push_back(i);
    //copy(lst.cbegin(),lst.cend(),vec.begin());  ������Ŀ����������Ҫ��������������һ�����Ԫ��,it's important,vital,crucial
    copy(lst.cbegin(),lst.cend(),back_inserter(vec));
    for(auto c:vec)
    {
        cout<<c<<' ';
    }
    cout<<endl;



    return 0;
}
