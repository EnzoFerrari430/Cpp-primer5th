#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
for_each��ʵ��

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
    Sum():sum{0} { } //C++11��ʼ����ʹ��{}�ĳ�ʼ���б���г�ʼ��
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

    // ��ÿ�������� Sum::operator()
    Sum s = std::for_each(nums.begin(), nums.end(), Sum());  //������õ���ʲô����

    std::cout << "after: ";
    std::for_each(nums.begin(), nums.end(), print);
    std::cout << '\n';
    std::cout << "sum: " << s.sum << '\n';



    return 0;
}
