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

	/*重写非虚函数-不允许的*/
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
	pb = &b;//基类指针指向基类对象
	pb->fun1();
	pb->fun1(3);

	cout << "***************\n";
	pb = &d;//基类指针指向派生类对象
	pb->fun1();//*****************注意******************

	pb->fun1(3);//该派生类对象（通过基类指针）可以调用（被隐藏的）基类函数
	pd = &d;//派生类指针指向派生类对象

	pd->fun1();//*******************注意*************

	/********************注意*************
	同一对象在不同指针指向时调用了不同函数，因此不可重写非虚函数*/

	//d.fun1(3);//error,被隐藏
	return 0;
}