#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <cctype>
#include <cstddef>
using namespace std;
int main()
{
    int ia1[] = {0,1,2,3,4,5};
    int ia2[] = {0,1,2,3,4,5,6};

    int i;
    int n1,n2;
    n1 = end(ia1) - begin(ia1);
    n2 = end(ia2) - begin(ia2);
    if(n1 == n2)
    {
        int length = n1 -1;
        for(i = 0;i<length;i++)
        {
            if(ia1[i] != ia2[i])
            {
                cout<<"�ڵ�"<<i<<"λ�����ݲ���"<<endl;
                return 0;
            }
        }
        cout<<"2���������"<<endl;
    }
    else
    {
        cout<<"2�����鳤�Ȳ���"<<endl;
    }


    return 0;
}
