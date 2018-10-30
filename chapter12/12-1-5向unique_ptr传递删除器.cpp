#include <iostream>
#include <string>
#include <memory>
using namespace std;

/*
    与shared_ptr不同，重载一个unique_ptr的删除器必须在尖括号中unique_ptr指向类型之后提供删除器类型
    //p指向一个类型为objT的对象，并使用一个类型为delT的对象释放objT对象
    //它会调用一个名为fcn的delT类型对象
    unique_ptr<objT,delT> p(new objT,fcn);
*/

struct connection
{
    string ip;
    int port;
    connection(string ip_,int port_):ip(ip_),port(port_){}
};

struct destination
{
    string ip;
    int port;
    destination(string ip_,int port_):ip(ip_),port(port_){}
};

//创建连接
connection connect(destination* pDest)
{
    unique_ptr<connection> pConn(new connection(pDest->ip,pDest->port));
    cout<<"creating connection..."<<endl;
    return *pConn;
}

void disconnect(connection Conn)
{
    cout<<"connection close("<<Conn.ip<<":"<<Conn.port<<")"<<endl;
}

void end_connection(connection* pConn)
{
    disconnect(*pConn);
}

//开始连接
void f(destination &d)
{
    connection conn = connect( &d );
    unique_ptr<connection,decltype(end_connection)*> p(&conn,end_connection);
    cout<<"p.use_count: "<<endl;
    cout<<"connectioning now..."<<endl;
}

int main()
{
    destination dest("127.0.0.1",3306);
    f(dest);
    return 0;
}
