Point global;
Point foo_bar( Point arg )
{
    Point local = arg,*heap = new Point( global );
    *heap = local;
    Point pa[4] = {local,*heap};
    return *heap;
}
1. Point local = arg  将arg拷贝给了local
2. *heap = local  将local拷贝到heap指定的地址中
3. Point pa[4] = {local,*heap};  将local和*heap拷贝给数组的前2个元素
4. return *heap
疑点： *heap = new Point( global )  这里new 的构造函数里的实参没有用引用
