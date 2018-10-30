#include <iostream>
#include <string>
#include <stack>
#include <deque>
using namespace std;
int main()
{
    //cout<<'6' + '7' - '0' - '0'<<endl;
    bool flag = false;
    string exp;
    cin>>exp;
    stack<char> res;
    for(string::size_type i = 0 ; i<exp.size() ; ++i)
    {
        if( exp[i] == '(' )
        {
            flag = true;
            res.push(exp[i]);
        }
        else if(exp[i] == ')' )
        {
            res.push(exp[i]);
            flag = false;
        }
        else if( flag == true )
        {
            res.push(exp[i]);
        }
    }
    cout<<res.size()<<endl;
    while( !res.empty() )
    {
        cout<<res.top()<<' ';
        res.pop();
    }

    return 0;
}
