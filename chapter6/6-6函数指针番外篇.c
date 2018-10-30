#include <stdio.h>

typedef int (*func)();  //ָ������ָ��

int func3()
{
    printf("In function 3......\n");
    return 0;
}

func func2(int a)  //func2����ָ������ָ��
{
    printf("input parameter is: %d\n", a);
    return func3;  //����func3�ĵ�ַ
}


int main()
{
    func (*myFuncPointer)(int) = func2;  //��func2�ĵ�ַ����myFuncPointer
    func returnvalue = myFuncPointer(1111);  //ִ��func2(1111)  func3�ĵ�ַ����returnvalue
    int func3_return = returnvalue();  //����func3  ���ص�0����func3_return
    printf("Func3 return value is: %d\n", func3_return);
    return 0;

    /*
        input paramter is: 1111
        Infunction 3......
        Func3 return value is: 0
    */

}
