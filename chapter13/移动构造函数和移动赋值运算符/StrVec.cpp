#include "StrVec.h"


void StrVec::push_back(const std::string& s )
{
    chk_n_alloc();  //确保有空间容纳新的元素

    //在first_free指向的元素中构造s的副本
    alloc.construct(first_free++,s);
}

//在拷贝或者赋值StrVec时使用该函数，该函数返回一个指针的pair，2个指针分别指向新空间的开始位置和拷贝的尾后位置
std::pair<std::string*,std::string*> StrVec::alloc_n_copy(const std::string* b,const std::string* e)
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

//移动构造函数，如果不想让其抛出异常的话，声明和定义（如果定义在类外）都要指定noexcept
StrVec::StrVec(StrVec &&s) noexcept
:elements(s.elements),first_free(s.first_free),cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
    //令s进入这样的状态，对其进行析构函数是安全的。
    //将右值StrVec的指针全都赋值个新对象的对应指针而老对象的指针全部指向nullptr，这样就不用再申请内存。因为老的对象本来就是要被删除的
}

StrVec::StrVec(std::initializer_list<std::string> il)
{
    elements = first_free = cap = nullptr;

    for(auto it = il.begin() ; it != il.end() ; ++it)
    {
        chk_n_alloc();
        alloc.construct(first_free++,*it);
    }
}


std::string StrVec::at(size_t num)
{
    size_t i = 0;
    while(i < num)
    {
        ++i;
    }
    return *(elements + i);  //还需要差错检验，防止num过大，超出first_free或者cap，返回2种错误的方式
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

//移动赋值运算符
StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
    //检测自己给自己赋值
    //这里的rhs是一个右值。我们也要进行检查的原因是此右值可能是move调用的结果
    if( this != &rhs )
    {
        free();  //释放已有元素
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        //将rhs置于可析构状态
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}


void StrVec::reallocate()
{
    //分配当前2倍大小的内存空间
    auto newcapacity = size()? 2*size() : 1;
    //分配新的内存
    auto newdata = alloc.allocate(newcapacity);  //newdata指向这块内容空间首地址

    auto dest = newdata;   //指向新数组中下一个空闲位置
    auto elem = elements;  //指向旧数组中下一个元素

    for(size_t i = 0; i!= size() ; ++i)
    {
        alloc.construct(dest++,std::move(*elem++));
    }
    free();  //完成元素移动就释放旧内存空间
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;


}


void StrVec::reserve(size_t new_cap)
{
    if( new_cap <= capacity() )
    {
        return ;
    }
    auto newdata = alloc.allocate(new_cap);

    auto dest = newdata;
    auto elem = elements;

    for(size_t i = 0 ; i != size() ; ++i)
    {
        alloc.construct(dest++,std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

void StrVec::resize( size_t cnt,const std::string& s )
{
    if( cnt < size() )
    {
        while(first_free != elements + cnt)
        {
            alloc.destroy(--first_free);
        }
    }
    else if( cnt > size() )
    {
        while( cnt > capacity() )
        {
            reallocate();
        }
        for( size_t i = size() ; i != cnt ; ++i  )
        {
            alloc.construct(first_free++,s);
        }
    }
}
