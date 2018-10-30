#include <iostream>
#include <vector>
using namespace std;
//9.34  有一个奇数就会无限循环
int main()
{
    vector<int> vi{1,2,2,2,2,2,2};
    auto iter = vi.begin();
    while(iter != vi.end())
    {
        if(*iter % 2)
            iter = vi.insert(iter,*iter);  //插入的位置在iter之前，然后返回新元素的迭代器。所以此时的迭代器在原来位置的前一位，就无限循环
        ++iter;
    }
    for(auto c : vi)
        cout<<c<<' ';
    cout<<endl;


    return 0;
}
