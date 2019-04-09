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

class shape
{
public:
	shape();
	shape(const shape& s);
	~shape();
	void set() {};////在子类重载？
	double area() { cout << "\t\t\t（基）shape面积计算函数\t" << this << endl; };//在子类重载？
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
	double area();
	void set(double x, double y);
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

double rectangle::area()
{
	cout << "\t\t\t（子）rectangle面积计算函数\t" << this << endl; //在子类重载？
	return a * b;
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
	void set(double r);
	double area() {
		cout << "\t\t\t（子）circle面积计算函数\t" << this << endl; //在子类重载？
		return 3.14*radius*radius;
	}
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

void circle::set(double r)
{
	radius = r;
}

class square :public rectangle
{
public:
	square();
	~square();
	void set(double len);
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

void square::set(double len)
{
	rectangle::set(len, len);
}

int main()
{
	string type;
	cout << "请输入形状的类别：";
	cin >> type;
	if (type == "rectangle")
	{
		double x, y;
		rectangle figure;//创建派生类的对象
		cout << "请输入矩形长和宽：";
		cin >> x >> y;
		figure.set(x, y);
		cout << "面积为：" << figure.area() << endl;
	}
	else if (type == "square")
	{
		double len;
		square figure;
		cout << "请输入正方形的边长：";
		cin >> len;
		figure.set(len);
		cout << "面积为：" << figure.area() << endl;
	}
	else if (type == "circle")
	{
		double len;
		circle figure;
		cout << "请输入圆的半径：";
		cin >> len;
		figure.set(len);
		cout << "面积为：" << figure.area() << endl;
	}
	return 0;
}