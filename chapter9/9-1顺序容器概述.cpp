#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
��׼���е�˳������
vector          �ɱ��С������.֧�ֿ���������ʡ���β��֮���λ�ò����ɾ��Ԫ�ؿ��ܻ���
deque           ˫�˶��С�֧�ֿ���������ʡ���ͷβλ�ò���ɾ�����ٶȺܿ�
list            ˫������ֻ֧��˫��˳����ʡ���list���κ�λ�ý��в���ɾ�������ٶȶ��ܿ�
forward_list    ��������ֻ֧�ֵ���˳����ʡ��������κ�λ�ý��в���ɾ���ٶȶ��ܿ�
array           �̶���С���顣֧�ֿ��������ʡ��������ɾ��Ԫ��
string          ��vector���Ƶ���������ר�����ڱ����ַ���������ʿ졣��β������ɾ���ٶȿ�



��ϰ9.1
a.list
b.deque
c.vector

*/

int main()
{

    vector<int> ival;
    cout<<ival.max_size()<<endl;


    return 0;
}
