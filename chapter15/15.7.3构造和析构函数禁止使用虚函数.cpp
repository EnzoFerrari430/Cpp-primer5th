#include <iostream>
using namespace std;

class base
{
public:
    base()
    {
        //cout<<"The base size is "<< size()<<endl;
    }
    base(const base &item);
private:
    virtual size_t size()
    {
        return sizeof(*this);
    }
protected:
    int i = 0;;
};

base::base(const base &item)
{
    i = item.i;
    //cout<<"copy construction in base"<<endl;
    cout<<"The base size is "<< i<<endl;
}

class derived : public base
{
public:
    derived()
    {
        //cout<<"The derived size is "<< size()<<endl;
    }
    derived(const derived& item);
private:
    virtual size_t size()override
    {
        return sizeof(*this);
    }
private:
    int c = 1;;
};

derived::derived(const derived &item):base(item)
{
    c = item.c;
    //cout<<"copy construction in derived"<<endl;
    cout<<"The derived size is "<< c<<endl;
}

int main()
{
    //derived d;
    //base b;
    //base *pb = new derived;
    derived d;
    derived d1(d);
    return 0;
}
