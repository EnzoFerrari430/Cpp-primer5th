#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    /*
        string和vector的迭代器提供了更多的额外运算符
        1.iter+n 迭代器指示的位置与原来相比前进了n个元素，结果迭代器指向容器内的一个元素，或尾元素的下一元素
        2.iter-n 迭代器指示的位置与原来相比后退了n个元素，结果迭代器指向容器内的一个元素，或尾元素的下一元素
        3.iter += n 迭代器加法的复合语句，将iter + n的结果赋给iter
        4.iter -= n 迭代器加法的复合语句，将iter - n的结果赋给iter
        5.iter1 - iter2 两个迭代器之间的距离，这两个迭代器指向的是同一个容器中的元素或者尾元素的下一位置
        6.> >= < <= 两个迭代器位置的比较，这两个迭代器指向的是同一个容器中的元素或者尾元素的下一位置
    */
    vector<int> s1;
    int num;
    while(cin>>num)
    {
        s1.push_back(num);
    }
    auto beg = s1.begin();
    auto edd = s1.end();
    auto mid = s1.begin() + (edd - beg)/2;
    //auto mid2 = (edd + beg)/2;
    //不可以！！！因为上面第一条说明已经说了，相加的结果必须指向容器内的一个元素或尾元素,先相加肯定不符合这一条件
    cout<<*mid<<endl;
    //cout<<*mid2<<endl;

    return 0;
}
