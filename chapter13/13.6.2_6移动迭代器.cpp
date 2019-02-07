#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <utility>


/*

    C++11新标准库中定义了一种移动迭代器适配器
    ！！！一个移动迭代器通过改变给定迭代器的解引用运算符的行为来适配此迭代器。


    一个迭代器的解引用运算符返回一个指向元素的  左值
    移动迭代器的解引用运算符生成一个右值引用


    make_move_iterator函数将一个普通的迭代器转换为一个移动迭代器，
    这个函数接受一个迭代器参数，返回一个移动迭代器


    原迭代器的所有其他操作在移动迭代器上都照常工作。所以可以将移动迭代器传递给uninitialized_copy
*/


class StrVec
{
public:
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){};  //默认构造函数
    StrVec(const StrVec&);  //拷贝构造函数，参数一定是引用。如果不是引用类型，值传递的话。实参传进形参就要进行一次拷贝构造，但是我们这里都还没有完成拷贝构造。这就形成了矛盾。
    StrVec& operator=(const StrVec&);  //这里参数使用引用  1.防止类没有定义拷贝构造函数之后，使用默认的拷贝构造函数造成的未知影响。2.实参传进形参会进行一次拷贝，需要花费CPU的开销

    ~StrVec();

    //类型vector的一些接口函数
    std::string* begin()const{return elements;}  //stl的特性
    std::string* end()const{return first_free;}
    // !!!C++中const 引用的是对象时只能访问该对象的const 函数，因为其他函数有可能会修改该对象的成员，编译器为了避免该类事情发生，会认为调用非const函数是错误的。
    void push_back(const std::string&);
    size_t size() const {return first_free - elements;}  //注意！！:2个同类型，指向同一个数组的指针相减，结果并不是两个指针数值上的差，而是把这个差除以指针指向类型的大小的结果。
    size_t capacity() const {return cap - elements;}  //返回容量

    bool empty() const {return (first_free - elements)? false : true; }  //是否为空，是空返回true，否则返回false







private:

    std::allocator<std::string> alloc;  //分配元素

    //4个工具函数
    void free();  //销毁元素，并释放内存
    void reallocate();  //获得更多的内存并拷贝已有的元素
    //确保StrVec至少有容纳一个新元素的空间.如果没有空间添加新元素，该函数调用reallocate来分配更多的空间
    void chk_n_alloc(){
        if( size() == capacity() )
        {
            reallocate();
        }
    }

    //分配内存，并拷贝一个给定范围中的元素,参数1,2表示一个范围中的元素
    std::pair<std::string*,std::string*> alloc_n_copy(const std::string* ,const std::string*);


    std::string* elements;
    std::string* first_free;
    std::string* cap;
};


void StrVec::push_back(const std::string& s )
{
    chk_n_alloc();  //确保有空间容纳新的元素

    //在first_free指向的元素中构造s的副本
    alloc.construct(first_free++,s);
}

//在拷贝或者赋值StrVec时使用该函数，该函数返回一个指针的pair，2个指针分别指向新空间的开始位置和拷贝的尾后位置
std::pair<std::string* ,std::string*> StrVec::alloc_n_copy(const std::string* b,const std::string* e)
{
    //data是指针，指向alloc申请的原始空间的首地址
    auto data = alloc.allocate(e - b);

    //可以返回花括号列表来对临时量进行初始化。参数一是内存空间的首地址，参数二是一个函数，用b，e表示的一个范围来初始化data为首的内存地址，返回尾后迭代器。这里就是string指针
    return {data,uninitialized_copy(b,e,data)};
}

//free函数的功能：1.destroy元素 2.释放StrVec自己分配的内存空间
void StrVec::free()
{
    //不能传递给deallocate一个空指针，如果elements为空，函数什么也不做
    if(elements)
    {
        //逆序销毁元素
        for(auto p = first_free; p!= elements;)
        {
            //destroy对p指向的元素进行析构函数
            alloc.destroy(--p);
        }
        alloc.deallocate(elements,cap - elements);
    }
}



//拷贝构造函数
StrVec::StrVec(const StrVec& s)
{
    //调用alloc_n_copy分配空间以容纳与s中一样多的元素
    //newdata的类型是pair<string*,string*>
    auto newdata = alloc_n_copy(s.begin(),s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}


//析构函数
StrVec::~StrVec()
{
    free();
}


StrVec& StrVec::operator=(const StrVec& rhs)
{
    //先将数据拷贝出来,这么做的好处是可以处理自己给自己赋值的情况了
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

//用移动迭代器的知识重写该函数
//void StrVec::reallocate()
//{
//    //分配当前2倍大小的内存空间
//    auto newcapacity = size()? 2*size() : 1;
//    //分配新的内存
//    auto newdata = alloc.allocate(newcapacity);  //newdata指向这块内容空间首地址
//
//    auto dest = newdata;   //指向新数组中下一个空闲位置
//    auto elem = elements;  //指向旧数组中下一个元素
//
//    for(size_t i = 0; i!= size() ;++i)
//    {
//        alloc.construct(dest++,std::move(*elem++));
//    }
//    free();  //完成元素移动就释放旧内存空间
//    elements = newdata;
//    first_free = dest;
//    cap = elements + newcapacity;
//
//
//}

void StrVec::reallocate()
{
    //分配当前2配大小的空间
    auto newcapacity = size()? 2*size() : 1;
    auto first = alloc.allocate(newcapacity);

    //移动元素
    //uninitialized_copy(inputit first,inputit last,forwardit d_first)  将first last表示范围内的元素复制到d_first为首的未初始化的内存中
    auto last = uninitialized_copy( make_move_iterator(begin()),make_move_iterator(end()),first );  //返回最后复制元素的尾后迭代器
    free();  //释放旧空间
    elements = first;  //更新指针
    first_free = last;
    cap = elements + newcapacity;
    std::cout<<"move iterator makes reallocate more memory"<<std::endl;
}

int main()
{
    StrVec sv;
    sv.push_back("hello1");
    sv.push_back("hello2");
    sv.push_back("hello3");
    sv.push_back("hello4");
    sv.push_back("hello5");
    sv.push_back("hello6");




    for( auto it = sv.begin(); it != sv.end(); ++it )
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;


    return 0;
}
