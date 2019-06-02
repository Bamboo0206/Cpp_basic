/*3、继承与派生实验
编写C++程序完成“形状”的以下功能：
（1） 声明一个基类 Shape（形状），其中包含一个方法来计算面积；
（2） 从 Shape 派生两个类：矩形类和圆形类；
（3） 从矩形类派生正方形类；
（4） 分别实现派生类构造函数、析构函数和其他方法；
（5） 创建派生类的对象，观察构造函数、析构函数调用次序；
（提示及要求：1，可通过在构造与析构函数中加入输出提示信息的方式观察
相关调用；可以使用 system("pause")进行程序的暂停；2，能够理解并说明每
一次构造与析构函数调用是哪个对象的调用，并观察和解释相关调用顺序及
其原因）
（6） 对不同对象计算面积。
*/
#include<iostream>
#include<string>
using namespace std;

class shape//抽象类
{
public:
	shape();
	shape(const shape& s);
	virtual ~shape();//虚析构函数，必须为虚析构函数，否则析构时只调用shape的析构函数
	virtual double area() = 0;//纯虚函数
	virtual void set(double x = 0, double y = 0) = 0;
private:

};

shape::shape()
{
	cout << "\t\t\t（基）shape默认构造函数\t" << this << endl;
}

shape::shape(const shape & s)
{
	cout << "\t\t\t（基）shape拷贝构造函数\t" << this << endl;
}

shape::~shape()
{
	cout << "\t\t\t（基）shape析构函数\t" << this << endl;
}


class rectangle :public shape
{
public:
	rectangle();
	~rectangle();
	virtual double area()override { return a * b; }
	virtual void set(double x, double y)override;
private:
	double a, b;//矩形形的长和宽
};

rectangle::rectangle()
{
	a = 0;
	b = 0;
	cout << "\t\t\t（子）rectangle默认构造函数\t" << this << endl;
}

rectangle::~rectangle()
{
	cout << "\t\t\t（子）rectangle析构函数\t" << this << endl;
}

void rectangle::set(double x, double y)
{
	a = x;
	b = y;
}

class circle :public shape
{
public:
	circle();
	~circle();
	virtual void set(double r, double y)override;
	virtual double area()override { return 3.14*radius*radius; }
private:
	double radius;
};

circle::circle()
	:shape()
{
	radius = 0;
	cout << "\t\t\t（子）circle默认构造函数\t" << this << endl;
}

circle ::~circle()
{
	cout << "\t\t\t（子）circle析构函数\t" << this << endl;
}

void circle::set(double r, double y)
{
	radius = r;
}

class square :public rectangle
{
public:
	square();
	~square();
	virtual void set(double len, double y)override;
private:

};

square::square()
{
	cout << "\t\t\t（孙）square默认构造函数\t" << this << endl;
}

square::~square()
{
	cout << "\t\t\t（孙）square析构函数\t" << this << endl;
}

void square::set(double len, double y)
{
	rectangle::set(len, len);
}

void check_cin();//输入合法性检验

int main()
{
	//shape a;//error 抽象类不允许实例化
	shape *figure = NULL;//基类指针
	string type;
	cout << "请输入形状的类别(rectangle/square/circle)：";
	cin >> type;
	if (type == "rectangle")//string类==运算符重载
	{
		double x, y;
		figure = new rectangle;
		cout << "请输入矩形长和宽：";
		cin >> x >> y;
		check_cin();
		figure->set(x, y);
		cout << "面积为：" << figure->area() << endl;
	}
	else if (type == "square")
	{
		double len;
		figure = new square;
		cout << "请输入正方形的边长：";
		cin >> len;
		check_cin();
		figure->set(len);
		cout << "面积为：" << figure->area() << endl;
	}
	else if (type == "circle")
	{
		double len;
		figure = new circle;
		cout << "请输入圆的半径：";
		cin >> len;
		check_cin();
		figure->set(len);
		cout << "面积为：" << figure->area() << endl;//调用的是rectangle的面积计算函数
	}
	else
	{
		cout << "不存在的类型" << endl;
	}
	if (figure) delete figure;

	system("pause");
	return 0;
}

void check_cin()//输入合法性检验
{
	if (!cin)
	{
		cout << "input error！" << endl;
		exit(0);
	}
}
