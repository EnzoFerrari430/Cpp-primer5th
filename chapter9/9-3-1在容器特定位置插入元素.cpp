#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
using namespace std;
/*
    vector��deque��list��string��֧��insert��Ա
    forward_list�ṩ��������insert��Ա
*/
int main()
{
    //����һ�Ե�������һ����ʼ���б��insert�汾
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
