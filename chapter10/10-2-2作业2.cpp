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
    //copy(lst.cbegin(),lst.cend(),vec.begin());  拷贝的目的序列至少要包含与输入序列一样多的元素,it's important,vital,crucial
    copy(lst.cbegin(),lst.cend(),back_inserter(vec));
    for(auto c:vec)
    {
        cout<<c<<' ';
    }
    cout<<endl;



    return 0;
}
