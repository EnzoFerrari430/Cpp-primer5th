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
    //����̬�����int42�ĵ�ַq��ֵ��r��֮ǰrָ��Ķ�̬������ڴ��û�취�ͷ���

    auto q2 = make_shared<int>(42);
    auto r2 = make_shared<int>(100);
    r2 = q2;
    //r2ָ��ĵ�ַ ���ô�����һ��������Զ��ͷ� q2�����ô�����һ



    return 0;
}
