Point global;
Point foo_bar( Point arg )
{
    Point local = arg,*heap = new Point( global );
    *heap = local;
    Point pa[4] = {local,*heap};
    return *heap;
}
1. Point local = arg  ��arg��������local
2. *heap = local  ��local������heapָ���ĵ�ַ��
3. Point pa[4] = {local,*heap};  ��local��*heap�����������ǰ2��Ԫ��
4. return *heap
�ɵ㣺 *heap = new Point( global )  ����new �Ĺ��캯�����ʵ��û��������
