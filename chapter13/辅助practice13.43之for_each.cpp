#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
for_each的实现

template<class InputIt, class UnaryFunction>
UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction f)
{
    for (; first != last; ++first) {
        f(*first);
    }
    return f;
}

*/

struct Sum
{
    Sum():sum{0} { } //C++11开始允许使用{}的初始化列表进行初始化
    void operator()(int n){sum += n;}
    int sum;
};

int main()
{
    std::vector<int> nums{3, 4, 2, 8, 15, 267};

    auto print = [](const int& n)
    {
        std::cout << " " << n;
    };

    std::cout << "before:";
    std::for_each(nums.begin(), nums.end(), print);
    std::cout << '\n';

    std::for_each(nums.begin(), nums.end(), [](int &n){n++;});

    // 对每个数调用 Sum::operator()
    Sum s = std::for_each(nums.begin(), nums.end(), Sum());  //这里调用的是什么函数

    std::cout << "after: ";
    std::for_each(nums.begin(), nums.end(), print);
    std::cout << '\n';
    std::cout << "sum: " << s.sum << '\n';



    return 0;
}
