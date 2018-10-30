#include <stdio.h>

typedef int (*func)();  //指向函数的指针

int func3()
{
    printf("In function 3......\n");
    return 0;
}

func func2(int a)  //func2返回指向函数的指针
{
    printf("input parameter is: %d\n", a);
    return func3;  //返回func3的地址
}


int main()
{
    func (*myFuncPointer)(int) = func2;  //将func2的地址赋给myFuncPointer
    func returnvalue = myFuncPointer(1111);  //执行func2(1111)  func3的地址赋给returnvalue
    int func3_return = returnvalue();  //运行func3  返回的0赋给func3_return
    printf("Func3 return value is: %d\n", func3_return);
    return 0;

    /*
        input paramter is: 1111
        Infunction 3......
        Func3 return value is: 0
    */

}
