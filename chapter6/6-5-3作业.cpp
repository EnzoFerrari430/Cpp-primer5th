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
    vector<string> vi {"hehe","3213","ghgas","C++","python","java","C#","ruby","linux"}; //c++11������
    show(vi);


    //6.48  ������ ֻҪ������assert��һֱΪ��  assert������ڼ�鲻�ܷ����������� assert( sought == s )
    return 0;
}
