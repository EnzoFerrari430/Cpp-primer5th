bool fcn(const Sales_data *trans,Sales_data accum)
{
    Sales_data item1(*trans),item2(accum);
    return item1.isbn() != item2.isbn();
}

���﷢��������������
�ֲ�����item1 item2 ���ں�������ʱ�����٣�Sales_data��������������
��������ʱ������accum�������ڽ����������٣�Sales_data����������������
��Ȼ��������ʱ��trans��������Ҳ�����ˣ���������Sales_data��ָ�룬��������ָ���Sales_data����������ڽ���(ֻ��deleteָ��ʱ��ָ��Ķ�̬����������ڲŽ���)�����Բ����������������ĵ���
