#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //vector<int> vi(10);  这里先初始化了10个int 元素0000000000，再加上num后成了000000000012345678910
    vector<int> vi;
    int num;
    for(num = 1;num<=10;num++)
    {
        vi.push_back(num);
    }

    //初始化一个c指向vi的第一个元素，c相当于一个指针
    for(auto c = vi.begin();c!= vi.end(); c++)
    {
        *c = 2*(*c);
        cout<<*c<<" ";
    }



    return 0;
}
