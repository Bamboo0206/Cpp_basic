#include<iostream>
using namespace std;
class base
{
public:
	base();
	~base();

	//virtual void fun1() { cout << "base virtual fun1() called\n"; }
	void fun1() { cout << "base fun1() called\n"; }
	void fun1(int x) { cout << "base fun1(int x) called\n"; }
private:
	int a;
};

base::base()
{
}

base::~base()
{
}
class derived :public base
{
public:
	derived();
	~derived();

	/*��д���麯��-�������*/
	 void fun1() { cout << "derived virtual fun1() called\n"; }
private:

};

derived::derived()
{
}

derived::~derived()
{
}
int main()
{
	base *pb,b;
	derived  d,*pd;
	//derived &pd(b);//error
	//pd = &b;//error
	pb = &b;//����ָ��ָ��������
	pb->fun1();
	pb->fun1(3);

	cout << "***************\n";
	pb = &d;//����ָ��ָ�����������
	pb->fun1();//*****************ע��******************

	pb->fun1(3);//�����������ͨ������ָ�룩���Ե��ã������صģ����ຯ��
	pd = &d;//������ָ��ָ�����������

	pd->fun1();//*******************ע��*************

	/********************ע��*************
	ͬһ�����ڲ�ָͬ��ָ��ʱ�����˲�ͬ��������˲�����д���麯��*/

	//d.fun1(3);//error,������
	return 0;
}