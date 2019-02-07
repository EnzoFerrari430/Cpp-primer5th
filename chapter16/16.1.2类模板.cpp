#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;


/*
    为了使用类模板，我们必须在模板名后的尖括号中提供额外的信息----用来代替模板参数的模板实参列表

    vector就是一个类模板
*/

//实现12.1.1节中StrBlob的模板版本，命名为Blob
//在类模板的定义中，我们将模板参数当做替身，代替使用模板时用户需要提供的类型或值
template <typename T>
class Blob
{
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    //构造函数
    Blob();
    Blob(std::initializer_list<T> il);
    //Blob中元素的数目
    size_type size() const{return data->size();}
    bool empty()const{return data->empty();}
    //添加和删除元素
    void push_back(const T& t){data->push_back(t);}
    //移动版本
    void push_back(T &&t){data->push_back(std::move(t));}
    void pop_back();
    //元素访问
    T& back();
    T& operator[](size_type i);
private:
    std::shared_ptr<std::vector<T>> data;
    //若data[i]无效则抛出i
    void check(size_type i,const std::string &msg)const;
};
//Blob模板有一个名为T的模板参数类型，用来表示Blob保存的元素的类型
//当用户实例化Blob时，T就会被替换为特定的模板实参类型


//如果一个成员定义在类模板的内部，则该成员函数被隐式声明为内联函数
//类模板的每个实例都有其自己的版本的成员函数。
//因此要求定义在类模板外部的成员函数，必须以关键字template开始，后接类模板参数列表

//定义check成员
template <typename T>
void Blob<T>::check(size_type i,const std::string &msg)const
{
    if(i >= data->size())
    {
        throw std::out_of_range(msg);
    }
}

//下标运算符和back函数用模板参数指出返回类型，其他不变
template <typename T>
T& Blob<T>::back()
{
    check(0,"back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
    //如果i太大会抛出异常，阻止访问一个不存在的元素
    check(i,"subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0,"pop_back on empty Blob");
    data->pop_back();
}

//和其他定义在类模板外的成员一样，类模板的构造函数定义也要以模板参数开始
template <typename T>
Blob<T>::Blob():data(std::make_shared<std::vector<T>>()){}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):data(std::make_shared<std::vector<T>>(il)){}

int main()
{
    //使用类模板时，我们必须提供额外信息。
    //这些额外信息是显示模板实参列表，它们被绑定到模板参数。
    //编译器使用这些模板实参来实例化出特定的类
    Blob<int> ia;  //空Blob<int>
    Blob<int> ia2 = {0,1,2,3,4};  //有5个元素的Blob<int>
    //当编译器从我们的Blob模板实例化出一个类时，它会重写Blob模板，将模板参数T的每个实例替换为给定的模板实参，在本例中是int


    //对我们指定的每一种元素类型，编译器都生成一个不同的类
    Blob<string> names;     //保存string的Blob
    Blob<double> prices;    //不同的元素类型

    //默认情况下，一个类模板的成员函数只有当程序用到它时才进行实例化
    //实例化Blob<int>和接受initializer_list<int>的构造函数
    Blob<int> squares = {0,1,2,3,4,5,6,7,8,9};
    //实例化Blob<int>::size()const
    for(size_t i = 0 ; i != squares.size() ; ++i)
    {
        squares[i] = i*i;  //实例化Blob<int>::operator[](size_t)
    }

    return 0;
}
