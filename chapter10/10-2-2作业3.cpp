#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
using namespace std;
int main()
{
    vector<int> vec;
    vec.reserve(10);
    //fill_n(vec.begin(),10,0);  û�д�����û���κ�����
    fill_n(back_inserter(vec),10,0);
    for(auto c: vec)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    //10.8  back_inserterֻ�ǲ�����һ�����������,Ȼ�������������������в������
    return 0;
}
