/*2.1��дC++������ɡ�Բ�Ρ����¹��ܣ�
��1�� ����һ�� Point �࣬�����԰���������꣬�ṩ��������֮�����ķ�������Ҫ���û���������������ʱ���ܹ�Ĭ��Ϊ����ԭ�㣨0��0����
��2�� ����һ��Բ���࣬�����԰���Բ�ĺͰ뾶��
��3�� ��������Բ�ζ�����ʾ�û�����Բ������Ͱ뾶���ж�����Բ�Ƿ��ཻ������������
��4�� �۲�Բ�ζ����Լ� Point ���Ա�Ĺ��캯�������������ĵ��á�����ʾ��Ҫ��1����ͨ���ڹ��������������м��������ʾ��Ϣ�ķ�ʽ�۲�
��ص��ã�����ʹ�� system("pause")���г������ͣ��2���ܹ���Ⲣ˵��ÿһ�ι��������������������ĸ�����ĵ��ã����۲�ͽ�����ص���˳����ԭ��
*/

#include<iostream>
#include<cmath>
using namespace std;

/*��1�� ����һ�� Point �࣬�����԰���������꣬�ṩ��������֮�����ķ�������Ҫ���û���������������ʱ���ܹ�Ĭ��Ϊ����ԭ�㣨0��0����*/
class Point {
private:
	int x, y;

public:
	Point(int x, int y);
	Point();
	Point& operator=(const Point &p);
	Point(Point &p);
	~Point();//�������� 
	double distance_2point(Point &p2);
	void SetPoint(int x, int y);/*
	int getX(void) { return x; }
	int getY(void) { return y; }*/

};

Point::Point(int x, int y)//���캯��  
{
	this->x = x;
	this->y = y;
	cout << "point�вι��캯��called��\t\t" << this << endl;
}
Point::Point()//���캯������ �޲� //Ҫ���û���������������ʱ���ܹ�Ĭ��Ϊ����ԭ�㣨0��0��
{
	this->x = 0;
	this->y = 0;
	cout << "point�޲ι��캯��called��\t\t" << this << endl;
}
Point & Point::operator=(const Point & p)
{
	if (this == &p) return *this;

	this->x = p.x;
	this->y = p.y;
	cout << "point��������غ���called��\t\t" << this << endl;
	return *this;
}
Point::Point(Point & p)
	:x(p.x), y(p.y)
{
	cout << "point�������캯��called��\t\t" << this << endl;
}
Point::~Point()
{
	cout << "point��������called��\t\t" << this << endl;
}
double Point::distance_2point(Point &p2)//��������֮��ľ���
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

/*��2�� ����һ��Բ���࣬�����԰���Բ�ĺͰ뾶��*/
class circle {
public:
	circle(Point &p, int r);
	circle() = delete; //�����޲ι��췽ʽ�� 
	circle& operator=(const circle &c);
	circle(circle &c);
	~circle();
	Point return_location(void);
	int get_radius(void) { return radius; };
private:
	Point location;//�����point�޲ι��캯������������
	int radius;
};
circle::circle(Point &p, int r) //�˴�������һ��point�����������point�޲ι��캯��
{
	//��ִ�к�����֮ǰ �����ص�����point�޲ι��캯������location
	cout << "circle�вι��캯��called��\t\t" << this << endl;
	location = p;//��ֵ���������
	radius = r;
}
circle & circle::operator=(const circle & c)
{
	if (this == &c) return *this;

	this->radius = c.radius;
	this->location = c.location;
	cout << "circle��������غ���called��\t\t" << this << endl;
	return *this;
}
circle::circle(circle & c)
	:location(c.location), radius(c.radius)
{
	cout << "circle�������캯��called��\t\t" << this << endl;
}
circle::~circle()
{
	cout << "circle��������called��\t\t" << this << endl;
}
Point circle::return_location(void)
{
	return this->location;
}


int main()
{
	/*��3�� ��������Բ�ζ�����ʾ�û�����Բ������Ͱ뾶���ж�����Բ�Ƿ��ཻ������������*/

	Point point_temp;
	int x, y, r;
	cout << "Please input coordinate of the center of the circle 1 (the default setting is (0,0):\n";
	char c;
	cin.get(c);
	if (c != '\n')//����ǻس�����������
	{
		cin.putback(c);//���ַ�c�Żػ�����
		cin >> x >> y;
		check_cin();//����Ϸ��Լ���
		point_temp.SetPoint(x, y);
	}
	cout << "Please input radius:\n";
	cin >> r;
	check_cin();
	circle C1(point_temp, r);

	point_temp.SetPoint(0, 0);

	cout << "Please input coordinate of the center of the circle 2 (the default setting is (0,0):\n";
	cin.get(c);//�̻س�
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
		point_temp.SetPoint();//ʹ��Ĭ�ϲ�����0��0��
	cout << "Please input radius:\n";
	cin >> r;
	check_cin();
	circle C2(point_temp, r);

	double len = 0;
	len = C1.return_location().distance_2point(point_temp);//�˴�return_location����ֵ��Point������ÿ������캯��
	if (len < C1.get_radius() + C2.get_radius())
		cout << "����Բ�ཻ\n";
	else if (len == C1.get_radius() + C2.get_radius())
		cout << "����Բ����\n";
	else
		cout << "����Բ����\n";

	return 0;
}
void check_cin()
{
	if (!cin)
	{
		cout << "input error��" << endl;
		exit(0);
	}
}
