#include <iostream>
#include <string>
#include <memory>
using namespace std;
/*
    ���ܿ���unique_ptr�Ĺ�����һ�����⣺���ǿ��Կ�����ֵһ����Ҫ���ٵ�unique_ptr��
*/

unique_ptr<int> clone(int p)
{
    return unique_ptr<int>(new int(p));
}

//�����Է���һ���ֲ�����Ŀ���
unique_ptr<int> clone_object(int p)
{
    unique_ptr<int> ret(new int(p));
    return ret;
}

int main()
{


    return 0;
}
