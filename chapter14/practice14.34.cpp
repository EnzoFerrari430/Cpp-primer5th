#include <iostream>

using namespace std;

class Judge
{
public:
    Judge( bool f = true, int c1 = 0,int c2 = 1):iStrue(f),data1(c1),data2(c2) {}
    int operator()(bool flag,int n1,int n2)const ;

private:
    bool iStrue;
    int data1;
    int data2;
};


int Judge::operator()(bool flag,int n1,int n2) const
{
    if(flag)
        return n1;
    else
        return n2;
}

int main()
{
    int a = 10;
    Judge jd;
    int s = jd( a>0,a,-a );
    cout<<s<<endl;
    int c = jd(a<0,a,-a);
    cout<<c<<endl;



    return 0;
}
