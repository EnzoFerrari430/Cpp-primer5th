#include <iostream>
#include <string>
#include <memory>
using namespace std;

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
    shared_ptr<connection> pConn(new connection(pDest->ip,pDest->port));
    cout<<"creating connection(" <<pConn.use_count()<< ")"<<endl;
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
    shared_ptr<connection> p(&conn,end_connection);
    cout<<"p.use_count: "<<p.use_count()<<endl;
    cout<<"connectioning now("<<p.use_count()<<")"<<endl;
}


int main()
{
    destination dest("127.0.0.1",3306);
    f(dest);

    return 0;
}
