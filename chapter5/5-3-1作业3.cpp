#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int get_value()
{
    srand((unsigned)time(0));  //���������
    int n;
    n = rand()%100;
    return n;
}
/*
ival��if�ڲ�����ģ�ival��������ֻ������if�涨����������

��1.�������if �ĳ�else if ���������if���������쵽������
2.��ival�Ķ������if�����棬����ival�������������������
(c) if (int ival = get_value())
    cout << "ival = " << ival << endl;
    if (!ival)
    cout << "ival = 0\n";
*/

//����else: C++�涨��else�����������δƥ���if��ƥ��
int main()
{
    if(int ival = get_value())
        cout<< "ival = "<<ival<<endl;
    else if(!ival)
        cout<< "ival = 0\n";

    return 0;
}
