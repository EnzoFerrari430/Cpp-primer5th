#include <iostream>
#include <string>
#include <memory>
using namespace std;

/*
    ��shared_ptr��ͬ������һ��unique_ptr��ɾ���������ڼ�������unique_ptrָ������֮���ṩɾ��������
    //pָ��һ������ΪobjT�Ķ��󣬲�ʹ��һ������ΪdelT�Ķ����ͷ�objT����
    //�������һ����Ϊfcn��delT���Ͷ���
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

//��������
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

//��ʼ����
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
