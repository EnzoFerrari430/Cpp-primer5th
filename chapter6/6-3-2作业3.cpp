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

    //6.34  ������0���ݹ鵽����� 0*1
    //6.35  ����val--����Ϊreturn��� factorial(val - 1) * val ������2��val���û᲻��ȷ��һ��valû���Լ���
    //6.35�ٷ� the recursive function will always use val as the parameter. a recursion loop would happen.
    return 0;
}
