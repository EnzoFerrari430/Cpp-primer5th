#include <iostream>
#include <string>
using namespace std;
/*
��������������
��Ҫ��main()��������ʵ�Σ�֮ǰд�ĳ��������main()�������ǿ��β��б�
����㣺ʹ��argv�е�ʵ��ʱ��һ��Ҫ�ǵÿ�ѡ������argv[1]��ʼ��argv[0]������ǳ�������֡�
*/
int main(int argc,char **argv)  //ʵ���б�
{
    string str;
    for(int i = 1;i!= argc;++i)
    {
        str += argv[i];
        str += " ";
    }
    cout<<str<<endl;
    return 0;
}
