#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    int *p1 = &ia[2];
    int *p2 = &ia[9];
    //p1 += p2 - p1;
    p1 = p1 + (p2 - p1);
    //������ȼ�
    //p1 = p1 + p2 - p1;  wrong ����ȼ�����p1 + p2 �����Խ��
    //cout<<*p1<<endl;

    int *beg = begin(ia);
    int *last = end(ia);
    for(;beg != last;beg ++)
    {
        *beg = 0;
    }
    for(auto c:ia)
    {
        cout<<c<<" ";
    }
    cout<<endl;




    return 0;
}
