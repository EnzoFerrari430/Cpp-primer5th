#include <iostream>

int reused = 42;  //ȫ��������
int main()
{
    int unique = 0;  //��������
    std::cout<<reused<<" "<<unique<<std::endl;

    int reused = 0;  //������ȫ�ֱ���
    std::cout<<reused<<" "<<unique<<std::endl;
    //��ʾ����ȫ�ֱ���  ::����������� ���Ϊ��ʱ ��ȫ�������򷢳�����
    std::cout<<::reused<<" "<<unique<<std::endl;


    return 0;
}
