#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
/*
    无序容器在存储上组织为一个桶，每个桶保存0个或多个元素。无序容器使用一个哈希函数将元素映射到桶。为了访问一个元素，容器首先计算元素的
    哈希值，它指出应该搜索哪个桶。容器将具有特定哈希值的所有元素都保存在相同的桶中。如果可以重复关键字，那么所有具有相同关键字的元素
    也都会在同一个桶中。无序容器的性能依赖于哈希函数的质量和桶的数量和大小

    理想情况下，哈希函数还能将每个特定的值映射到唯一的桶。

无序容器管理操作
    桶接口
    c.bucket_count()        正在使用的桶的数目
    c.max_bucket_count()    容器能容纳的最多桶的数目
    c.bucket_size(n)        第n个桶中有多少个元素
    c.bucket(k)             关键字为k的元素在哪个桶中

    桶迭代
    local_iterator          访问桶中元素的迭代器类型
    const_local_iterator    桶迭代器的const版本
    c.begin(n) c.end(n)     桶n的首元素迭代器和尾后迭代器
    c.cbegin(n) c.cend(n)   const版本

    哈希策略
    c.load_factor()         每个桶的平均元素数量，返回float值
    c.max_load_factor()     c试图维护的平均桶大小，返回float值。c会在需要时添加新的桶，以使得load_factor <= max_load_factor
    c.rehash(n)             重组存储，使得bucket_count >= n，且bucket_count > size/max_load_factor
    c.reserve(n)            重组存储，使得c可以保存n个元素且不必rehash
*/


struct Sales_data
{
    //新成员：关于Sales_data对象的操作
    string isbn() const{return bookNo;}
    //在成员函数内部，我们可以直接使用调用该函数的对象的成员，而无需通过访问运算符来做到这一点
    //isbn隐式的使用this指向成员 相当于 return this->bookNo;
    //请求该函数的对象的地址初始化this

    //参数列表之后的const关键字,这里的作用是修改隐式this指针的类型
    //默认情况下this的类型是指向类类型非常量版本的常量指针
    //在Sales_data成员函数中，this的类型是Sales_data *const  this保存的地址不能改，但是*this可以改.
    //所以在默认情况下this指针不能绑定到一个常量对象上
    //所以要把this指针声明成 const Sales_data *const，以提高函数的灵活性
    //因为this不在参数列表中，所以C++语法允许把const关键字放在成员函数的参数列表之后
    //这样this就成了指向常量的指针，所以isbn可以读取它的对象的成员 但是不能写入新值
    //这里的const用于判断

    Sales_data &combine(const Sales_data &);  //模仿赋值运算，所以用引用当成左值返回
    double avg_price() const;

    //数据成员
    string bookNo;
    unsigned units_sold = 0;  //★网上资料都说类的成员变量定义不允许直接初始化   这里有疑问
    double revenue = 0;
};



//Sales_data的非接口成员函数
Sales_data add(const Sales_data &,const Sales_data &);
std::ostream &print(std::ostream &,const Sales_data &);
std::istream &read(std::istream &,Sales_data &);

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;  //把rhs的成员加到this对象的成员上
    revenue += rhs.revenue;
    return *this;  //返回调用该函数的对象
}

//如果想要用自己定义的类来当做关键字的话，就要重载一个哈希值的重载函数，和一个代替 == 运算符的比较函数
size_t hasher(const Sales_data &sd)
{
    return hash<string>()(sd.isbn());
    /*
第一对括号生成一个hasher,然后第二对括号立即调用
相当于

std::hash<string> hasher;
return hasher(sd.isbn());

当年学前端的函数的时候有见过这种写法
*/
}

bool eqOp(const Sales_data &lhs,const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}


int main()
{
    //通过这些函数定义一个  unordered_multiset
    using SD_multiset = unordered_multiset<Sales_data,decltype(hasher)*,declval(eqOp)*>;
    //参数是桶大小、哈希函数指针、相等性判断运算符指针
    SD_multiset bookstore(42,hasher,eqOp);
    return 0;
}
