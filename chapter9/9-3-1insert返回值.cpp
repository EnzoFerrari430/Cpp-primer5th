#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
int main()
{
    //����ͨ��insert����ֵ���������е�һ���ض�λ�÷�������Ԫ��
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
