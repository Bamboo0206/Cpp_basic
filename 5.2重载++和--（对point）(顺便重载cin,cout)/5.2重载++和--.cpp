/*5.2 对Point类重载＋＋和――运算符
 编写C++程序完成以下功能：
（1） Point 类的属性包括点的坐标（x，y）；
（2） 实现 Point 类重载＋＋和――运算符：
 ++p，--p，p++，p--；
 ＋＋和――分别表示 x，y 增加或减少 1。*/

/*详细分析见OneNote*/
#include<iostream>
using namespace std;

/*（1） 定义一个 Point 类，其属性包括点的坐标*/
class Point {
private:
	int x, y;

public:
	Point(int x, int y);
	Point();
	Point& operator=(const Point &p);
	Point(Point &p);
	~Point();//析构函数 
	void SetPoint(int x, int y);
	Point& operator++();//前置类型，成员函数
	Point operator++(int);//后置类型，成员函数
	friend Point& operator--(Point& p);//前置类型，全局函数，Point类的友元
	friend Point operator--(Point& p, int);//后置类型，全局函数，Point类的友元
	friend istream& operator>>(istream &is, Point& p);//顺便重载cin，全局函数，Point类的友元
	friend ostream& operator<<(ostream &os, const Point& p);//顺便重载cout，全局函数，Point类的友元
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
Point & Point::operator=(const Point & p)//注意返回引用
{
	if (this == &p) return *this;//p=p的情况直接返回

	this->x = p.x;
	this->y = p.y;
	cout << "point赋值运算符重载函数called！\t\t" << this << endl;
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
void Point::SetPoint(int x = 0, int y = 0)
{//??????
	this->x = x;
	this->y = y;
}

Point & Point::operator++()//前置类型，成员函数
{
	x++;
	y++;
	cout << "\t\t前置++重载函数called！\t\t" << this << endl;
	return *this;
}

Point Point::operator++(int)//后置类型，成员函数
{
	Point temp(*this);
	this->x++;
	this->y++;
	cout << "\t\t后置++重载函数called！\t\t" << this << endl;
	return temp;//返回对象，调用拷贝构造函数，创建临时量，拷贝完析构temp，cout语句结束析构临时量
}

Point & operator--(Point & p)//前置类型，全局函数，Point类的友元
{
	p.x--;
	p.y--;
	cout << "\t\t前置--重载函数called！\t\t" << &p << endl;
	return p;
}

Point operator--(Point & p, int)//后置类型，全局函数，Point类的友元
{
	Point temp = p;//调用的还是拷贝构造函数而不是赋值运算符重载
	p.x--;
	p.y--;
	cout << "\t\t后置--重载函数called！\t\t" << &p << endl;
	return temp;//返回对象，调用拷贝构造函数，创建临时量，拷贝完析构temp，cout语句结束析构临时量
}

istream & operator>>(istream & is, Point & p)
{
	cout << "cin重载函数called！\t\t" << endl;
	is >> p.x >> p.y;
	if (!is)//输入正确性检验
	{
		cout << "input error！" << endl;
		exit(0);
	}
	return is;
}

ostream & operator<<(ostream & os, const Point & p)
{
	cout << "cout重载函数called！\t\t" << endl;
	os << "(" << p.x << "," << p.y << ")" << "\t\t\t\t\t" << &p << endl;
	return os;
}

int main()
{
	Point p;
	cout << "请输入两个整数作为点的坐标：" << endl;
	cin >> p;
	cout << "***************测试++******************\n";
	cout << (p++) << endl;  //等价于 p.operator++(0); 
	cout << p << endl;
	cout << (++p) << endl;   //等价于 p.operator++(); 
	cout << p << endl;
	cout << "\n***************测试--******************\n";
	cout << (p--) << endl;   //等价于 operator--(p,0); //后置--，输出的是临时量的值
	cout << p << endl;
	cout << (--p) << endl;    //等价于 operator--(p); 
	cout << p << endl;


	system("pause");
	return 0;
}