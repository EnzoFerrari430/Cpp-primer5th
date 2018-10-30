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
    process(shared_ptr<int>(p.get()));  //p.get()  �õ���shared_ptr��process����֮����ͷ� int 42���ڵ��ڴ棬ʹ��p��Ϊһ������ָ��
    cout<<p.use_count()<<endl;
    auto q = p;
    cout<<p.use_count()<<endl;
    cout<<"the int p now points to is: "<<*p<<endl;


    return 0;
}
