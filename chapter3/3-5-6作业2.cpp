#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
    int ia[3][4] = {0};

    //ʹ�����ͱ���
    using int_array = int[4];

    for(int_array &p :ia)
    {
        for(int q : p)
        {
            cout<<q<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    for(int_array *p = ia; p != ia +3;p++)
    {
        //qָ��ָ��p��ǰ�����еĵ�һ��Ԫ��
        for(int *q = *p; q != *p + 4;q++)
        {
            cout<<*q<<' ';
        }
        cout<<endl;
    }


    return 0;
}
