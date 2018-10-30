#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
int main()
{
    int *q = new int(42);
    int *r = new int(100);
    r = q;
    //将动态分配的int42的地址q赋值给r，之前r指向的动态分配的内存就没办法释放了

    auto q2 = make_shared<int>(42);
    auto r2 = make_shared<int>(100);
    r2 = q2;
    //r2指向的地址 引用次数减一，归零后自动释放 q2的引用次数加一



    return 0;
}
