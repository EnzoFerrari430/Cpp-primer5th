#include <iostream>
using namespace std;
int main()
{
    /*
        ��Χfor����﷨
        for(declaration:expression)
            statement

        expression��ʾ����һ������,�����б����飬vector��string�����͵Ķ���,��Щ���͵Ĺ�ͬ�ص���ӵ���ܷ��ص�������begin��end��Ա

        declaration����һ�������������е�ÿ��Ԫ�ض���ת���ɸ����͵ı���,��򵥵ľ���ʹ��auto����˵����
            �������Ҫ�������е�Ԫ��ִ��д��������ѭ������������������������


    */
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    //��Χ�����������������ͣ��������ܶ�Ԫ��ִ��д����
    for(auto &r : v)
        r *= 2;



    return 0;
}
