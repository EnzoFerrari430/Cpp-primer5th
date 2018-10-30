#include <iostream>
using namespace std;

typedef double Money;
string bal;
class Account
{
public:
    Money balance(){return bal;}  //balance函数体在整个类可见后才被处理，所以该函数return 名为bal的成员,而非外层作用域的string对象
private:
    //typedef int Money;  //不能重新定义Money，即使Account中定义的Money类型和外层作用域一致，但任然是错误的。一些编译器会通过这样的代码，而忽略代码有错的事实。
    Money bal;
};

int main()
{


    return 0;
}
