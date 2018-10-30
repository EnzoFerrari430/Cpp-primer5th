#include <iostream>
using namespace std;
int main()
{
    //ostream os;
    //os<<"please enter a value: "<<endl;
    cout<<"hello world 1";
    cout<<"hello world 2";
    cout<<"hello world 3";
    cout<<"hello world 4";
    cout<<"hello world 5";
    cout<<"hello world 6";
    cout<<"hello world 7";
    cout<<"hello world 8";
    cout<<"hello world 9";
    cout<<"hello world 10";
    cout<<"hello world 11";
    cout<<"hello world 12";
    cout<<"hello world 13";
    cout<<"hello world 14";
    cout<<"hello world 15";
    cout<<"hello world 16";
    //上述文本串 可能立即打印，可能被操作系统保存在缓冲区中，随后打印

    //导致缓冲刷新(数据真正写到输出设备或文件)的原因
    //1.程序正常结束
    //2.缓冲区满时，需要刷新缓冲，而后新的数据才能继续写入缓冲区
    //3.使用操作符如endl来显式的刷新缓冲区
    //4.每次输出操作之后，使用操作符unitbuf设置流的内部状态，来清空缓冲区
    //5.一个输出流被关联到另一个流。这种情况下，当读写被关联的流时，关联到的流的缓冲区会被刷新

    //刷新输出缓冲区
    cout<<"Hi!"<<endl;  //输出换行并刷新
    cout<<"Hi!"<<flush; //刷新缓冲区
    cout<<"Hi!"<<ends;  //输出空格并刷新



    //unitbuf操纵符:它告诉流接下来的每次写操作之后都进行一次flush操作。
    //nounitbuf操纵符:则重置流，使其恢复使用正常的系统管理的缓冲区刷新机制
    cout<<unitbuf;  //所有输出操作后都会立即刷新缓冲区
    cout<<nounitbuf;//回到正常的方式



    //关联输入和输出流
    //当一个输入流被关联到一个输出流时，任何试图从输入流读取数据的操作都会先刷新关联的输出流。标准库将cout和cin关联到一起，
    int n;
    cin>>n;  //之前还留在cout缓冲区中的数据都会被刷新打印出来

    return 0;
}
