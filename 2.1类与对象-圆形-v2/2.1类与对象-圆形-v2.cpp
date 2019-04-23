/*2.1编写C++程序完成“圆形”以下功能：
（1） 定义一个 Point 类，其属性包括点的坐标，提供计算两点之间距离的方法；（要求当用户不输入坐标数据时，能够默认为坐标原点（0，0））
（2） 定义一个圆形类，其属性包括圆心和半径；
（3） 创建两个圆形对象，提示用户输入圆心坐标和半径，判断两个圆是否相交，并输出结果；
（4） 观察圆形对象以及 Point 类成员的构造函数与析构函数的调用。（提示及要求：1，可通过在构造与析构函数中加入输出提示信息的方式观察
相关调用；可以使用 system("pause")进行程序的暂停；2，能够理解并说明每一次构造与析构函数调用是哪个对象的调用，并观察和解释相关调用顺序及其原因）
*/

#include<iostream>
#include<cmath>
using namespace std;

/*（1） 定义一个 Point 类，其属性包括点的坐标，提供计算两点之间距离的方法；（要求当用户不输入坐标数据时，能够默认为坐标原点（0，0））*/
class Point {
private:
	int x, y;

public:
	Point(int x, int y);
	Point();
	Point& operator=(const Point &p);
	Point(Point &p);
	~Point();//析构函数 
	double distance_2point(Point &p2);
	void SetPoint(int x, int y);/*
	int getX(void) { return x; }
	int getY(void) { return y; }*/

};

Point::Point(int x, int y)//构造函数  
{
	this->x = x;
	this->y = y;
	cout << "point有参构造函数called！\t\t" << this << endl;
}
Point::Point()//构造函数重载 无参 //要求当用户不输入坐标数据时，能够默认为坐标原点（0，0）
{
	this->x = 0;
	this->y = 0;
	cout << "point无参构造函数called！\t\t" << this << endl;
}
Point & Point::operator=(const Point & p)
{
	if (this == &p) return *this;

	this->x = p.x;
	this->y = p.y;
	cout << "point运算符重载函数called！\t\t" << this << endl;
	return *this;
}
Point::Point(Point & p)
	:x(p.x), y(p.y)
{
	cout << "point拷贝构造函数called！\t\t" << this << endl;
}
Point::~Point()
{
	cout << "point析构函数called！\t\t" << this << endl;
}
double Point::distance_2point(Point &p2)//计算两点之间的距离
{
	return sqrt((this->x - p2.x)*(this->x - p2.x)
		+ (this->y - p2.y)*(this->y - p2.y));
}
void Point::SetPoint(int x = 0, int y = 0)
{//??????
	this->x = x;
	this->y = y;
}

void check_cin();

/*（2） 定义一个圆形类，其属性包括圆心和半径；*/
class circle {
public:
	circle(Point &p, int r);
	circle() = delete; //屏蔽无参构造方式。 
	circle& operator=(const circle &c);
	circle(circle &c);
	~circle();
	Point return_location(void);
	int get_radius(void) { return radius; };
private:
	Point location;//会调用point无参构造函数和析构函数
	int radius;
};
circle::circle(Point &p, int r) //此处定义了一个point变量，会调用point无参构造函数
{
	//在执行函数体之前 隐含地调用了point无参构造函数构造location
	cout << "circle有参构造函数called！\t\t" << this << endl;
	location = p;//赋值运算符重载
	radius = r;
}
circle & circle::operator=(const circle & c)
{
	if (this == &c) return *this;

	this->radius = c.radius;
	this->location = c.location;
	cout << "circle运算符重载函数called！\t\t" << this << endl;
	return *this;
}
circle::circle(circle & c)
	:location(c.location), radius(c.radius)
{
	cout << "circle拷贝构造函数called！\t\t" << this << endl;
}
circle::~circle()
{
	cout << "circle析构函数called！\t\t" << this << endl;
}
Point circle::return_location(void)
{
	return this->location;
}


int main()
{
	/*（3） 创建两个圆形对象，提示用户输入圆心坐标和半径，判断两个圆是否相交，并输出结果；*/

	Point point_temp;
	int x, y, r;
	cout << "Please input coordinate of the center of the circle 1 (the default setting is (0,0):\n";
	char c;
	cin.get(c);
	if (c != '\n')//如果是回车则跳过输入
	{
		cin.putback(c);//将字符c放回缓冲区
		cin >> x >> y;
		check_cin();//输入合法性检验
		point_temp.SetPoint(x, y);
	}
	cout << "Please input radius:\n";
	cin >> r;
	check_cin();
	circle C1(point_temp, r);

	point_temp.SetPoint(0, 0);

	cout << "Please input coordinate of the center of the circle 2 (the default setting is (0,0):\n";
	cin.get(c);//吞回车
	c = 0;
	cin.get(c);
	if (c != '\n')
	{
		cin.putback(c);
		cin >> x >> y;
		check_cin();
		point_temp.SetPoint(x, y);
	}
	else
		point_temp.SetPoint();//使用默认参数（0，0）
	cout << "Please input radius:\n";
	cin >> r;
	check_cin();
	circle C2(point_temp, r);

	double len = 0;
	len = C1.return_location().distance_2point(point_temp);//此处return_location返回值是Point，会调用拷贝构造函数
	if (len < C1.get_radius() + C2.get_radius())
		cout << "两个圆相交\n";
	else if (len == C1.get_radius() + C2.get_radius())
		cout << "两个圆相切\n";
	else
		cout << "两个圆相离\n";

	return 0;
}
void check_cin()
{
	if (!cin)
	{
		cout << "input error！" << endl;
		exit(0);
	}
}
