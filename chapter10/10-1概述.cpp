#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
    //����ָ��������������ϵĵ�����һ�������ǿ�����find�������в���ֵ
    int ia[] = {27,210,12,47,109,83};
    int val = 83;
    int *result = find(begin(ia),end(ia),val);
    int *p = find(ia+1,ia+3,val);
    cout<<result<<endl;
    cout<<p<<endl;
    cout<<*result<<endl;
    cout<<*p<<endl;



    return 0;
}
