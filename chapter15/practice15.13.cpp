#include <iostream>
#include <string>
#include <ostream>
using namespace std;

class base
{
public:
    base(string a):basename(a){}
    string name()const {return basename;}
    virtual void print(ostream &os){os<<basename;}
private:
    string basename;
};

class derived : public base
{
public:
    derived(string s,int a):base(s),i(a){}
    int value()const {return i;}
    void print(ostream &os){  base::print(os);os<<" "<<i;}  //  ����base::����˵���������Իر��麯���Ļ���
private:
    int i;
};

int main()
{
    base b("helloworld");
    derived d("wz",330304);
    d.print(cout);

    base *pbase = &d;
    cout<<pbase->name()<<endl;
    //cout<<pbase->value()<<endl;

    return 0;
}
