#include <iostream>
#include <vector>
using namespace std;

void show(vector<int> vi)
{
    cout<<vi[0]<<' ';
    if(vi.size()>1)
    {
        vi.erase(vi.begin());
        show(vi);
    }
}

int main()
{
    vector<int> vi{0,1,2,3,4,5,6,7,8,9};
    show(vi);

    //6.34  不等于0，递归到最后有 0*1
    //6.35  不用val--是因为return语句 factorial(val - 1) * val 出现了2个val调用会不明确后一个val没有自减过
    //6.35官方 the recursive function will always use val as the parameter. a recursion loop would happen.
    return 0;
}
