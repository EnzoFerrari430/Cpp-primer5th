#include <iostream>
#include <memory>
using namespace std;

void process(shared_ptr<int> p)
{
    cout<<"inside the process function: "<<p.use_count()<<"\n";
}

int main()
{
    shared_ptr<int> p(new int(42));
    process(shared_ptr<int>(p.get()));  //p.get()  得到的shared_ptr在process结束之后就释放 int 42所在的内存，使得p称为一个空悬指针
    cout<<p.use_count()<<endl;
    auto q = p;
    cout<<p.use_count()<<endl;
    cout<<"the int p now points to is: "<<*p<<endl;


    return 0;
}
