#include <iostream>
#include <typeinfo>
#include <string>
#include <limits>

//2���ַ�����ֱ��ʹ��
//1.���ɴ�ӡ���ַ� �˸����������ַ�
//2.���⺬����ַ�

/*
\n ���з� \t �����Ʊ�� \a ������ \v �����Ʊ��
\b �˸�� \" ˫���� \\ ��б�� \? �ʺ� \'������
\r �س��� \f ��ֽ��
*/

template<class T>

char *judge(T a)
{
    return typeid(a).name();
}

int main()
{
    std::cout<<'\n';
    std::cout<<"\tHi!\n";  //���һ���Ʊ�� ���һ��Hi ���һ�����з�

    std::cout<<"Hi \x4dO\115!\n";  //���Hi MOM��ת����һ��   \x4d ��16���� 4d��ʮ���Ƶ�77 M��asc��  115��8����Ҳ��10���Ƶ�77
    //8�����������ֻ��3������ת��  \1155��ʾ��M5  ��\x��������ֶ�Ҫ����ת��

    //std::cout<<"\x1235\n";  //�������,charֻռ8λ

    //std::cout<<sizeof(char)<<std::endl;  //charռһ���ֽ� 8λ

    return 0;
}
