#include<iostream>
using namespace std;
int main()
{
	try 
	{
		/*����*/
		/*���ִ���*/
		throw ���� / ����;
	}
	catch (����)//������󲿷�ʵ�ε��βε�ǿ������ת��
	{
		try{}//����Ƕ��
		catch (){}
	}
	catch (����)
	{
		/*����*/
		/*���׳�����*/
		throw;//�������㣨�������ĺ�������
	}
	catch (...)//��ס�������ʹ���
	{

	}
}