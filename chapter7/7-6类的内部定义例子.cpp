#include <iostream>

class Account {
public:
    static double GetCircumference(const double& dR) { return 2 * dR * 3.1415926; }
    static constexpr double cd = 3.0;  //我们可以为静态成员提供const整数类型的类内初始值，不过要求静态成员必须是字面值类型的constexpr
};
//如果cd就是在内部使用，那么定义就不用分别定义，类内初始化就足够了，但如果在类外使用，就会出现编译错误
constexpr double Account::cd;  //有无这条语句会产生两种不同的结果

int main()
{
    //使用作用域运算符直接访问静态成员
    std::cout << Account::GetCircumference(Account::cd) << std::endl;
    return 0;
}
