/*

a)  template <typename T,U,typename V> void f1(T,U,V);
    U前面要加typename关键字，指明U是类型参数
b)  template <typename T> T f2(int &T);
    在作用域中，模板参数名不能重用,这里T重用为了函数参数名
c)  inline template <typename T> T foo(T,unsigned int*);
    inline关键字在模板参数列表之后，函数返回类型之前，
    应为
    template <typename T> inline T foo(T,unsigned int*);
d)  template <typename T> f4(T,T);
    没有返回类型
e)
typedef char Ctype;
template<typename Ctype> Ctype f5(Ctype a);
没错，上面typedef被屏蔽了



*/
