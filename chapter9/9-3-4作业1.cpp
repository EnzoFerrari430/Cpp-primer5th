#include <iostream>
#include <forward_list>
using namespace std;
int main()
{
    forward_list<int> fli{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    auto head = fli.begin();
    auto bhead = fli.before_begin();
    auto lst = fli.end();
    while(head != lst)
    {
        if(*head % 2)
        {
            head = fli.erase_after(bhead);  //删除bhead之后的元素
        }
        else
        {
            ++bhead;
            ++head;
        }
    }
    for(auto c:fli)
        cout<<c<<' ';
    cout<<endl;

    return 0;
}
