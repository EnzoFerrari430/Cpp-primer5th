#include <iostream>
using namespace std;
int main()
{
    auto old_state = cin.rdstate();
    cout<<(cin.rdstate())<<endl;
    int n;
    cin>>n;
    cout<<(cin.rdstate())<<endl;

    cin.clear();
    cout<<(cin.rdstate())<<endl;
    cin.sync();  //清空流
    cin>>n;
    cout<<(cin.rdstate())<<endl;
    cin.setstate(old_state);  //根据给定的标志位将流中的条件状态位置位
    cout<<(cin.rdstate())<<endl;
    //setstate()函数并不强制覆盖流的原状态，而是将括号内参数所代表的状态叠加到原始状态上。
    //clear() 函数将流状态设置成括号内参数所代表的状态，强制覆盖掉流的原状态。
    return 0;
}
