#include <iostream>
#include <string>

namespace primerLib
{
    //fun1
    void compute()
    {
        std::cout<<"function with no parameter in namespace primerLib"<<std::endl;
    }
    //fun2
    void compute(const void* a)
    {
        std::cout<<"function with parameter1: const void* in namespace primerLib"<<std::endl;
    }
}

//using primerLib::compute;
/*
using����������Ļ�
�����ռ�primerLib�е�fun1��fun2��������ȫ���������пɼ�
���Ժ���f�ĺ�ѡ������5��
�����к�����4������ȥfun1
ֻ��fun3�Ǿ�ȷƥ��
���Ի����fun3
*/
//fun3
void compute(int a)
{
    std::cout<<"function with parameter1: int in global"<<std::endl;
}
//fun4
void compute(double a,double b = 3.4)
{
    std::cout<<"function with parameter1: double and parameter2: double in global"<<std::endl;
}
//fun5
void compute(char* a,char* b = 0)
{
    std::cout<<"function with parameter1: char* and parameter2: char* in global"<<std::endl;
}

void f()
{
    using primerLib::compute;
    /*
    ԭ��p702:using�����ģ�������Ч��Χ��using�����ĵط���ʼ��һֱ��using�������ڵ����������Ϊֹ��
    �ڴ˹����У�����������ͬ��ʵ�彫������

    ���ԣ����������Ļ�ȫ���������е�����compute�����ᱻ����
    ��ѡ����ֻ��fun1��fun2
    ���к���ֻ��fun2����Ҫ��ʽת��ʵ�η���ƥ��
    */
    compute(0);
}

int main()
{
    f();

    return 0;
}
