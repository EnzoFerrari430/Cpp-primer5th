#include <iostream>
#include <vector>
#include <string>
using namespace std;

void show(vector<string> vi)
{
#ifndef NDEBUG
    cout<<"vi.size = "<<vi.size()<<endl;
#endif // NDEBUG

    cout<<vi[0]<<' ';
    if(vi.size()>1)
    {
        vi.erase(vi.begin());
        show(vi);
    }
}

int main()
{
    vector<string> vi {"hehe","3213","ghgas","C++","python","java","C#","ruby","linux"}; //c++11新特性
    show(vi);


    //6.48  无意义 只要有输入assert就一直为真  assert最好用于检查不能发生的事情如 assert( sought == s )
    return 0;
}
