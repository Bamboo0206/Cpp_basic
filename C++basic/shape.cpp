/*3���̳�������ʵ��
��дC++������ɡ���״�������¹��ܣ�
��1�� ����һ������ Shape����״�������а���һ�����������������
��2�� �� Shape ���������ࣺ�������Բ���ࣻ
��3�� �Ӿ����������������ࣻ
��4�� �ֱ�ʵ�������๹�캯������������������������
��5�� ����������Ķ��󣬹۲칹�캯���������������ô���
����ʾ��Ҫ��1����ͨ���ڹ��������������м��������ʾ��Ϣ�ķ�ʽ�۲�
��ص��ã�����ʹ�� system("pause")���г������ͣ��2���ܹ���Ⲣ˵��ÿ
һ�ι��������������������ĸ�����ĵ��ã����۲�ͽ�����ص���˳��
��ԭ��
��6�� �Բ�ͬ������������
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
	void set() {};////���������أ�
	double area() { cout << "\t\t\t������shape������㺯��\t" << this << endl; };//���������أ�
private:

};

shape::shape()
{
	cout << "\t\t\t������shapeĬ�Ϲ��캯��\t" << this << endl;
}

shape::shape(const shape & s)
{
	cout << "\t\t\t������shape�������캯��\t" << this << endl;
}

shape::~shape()
{
	cout << "\t\t\t������shape��������\t" << this << endl;
}


class rectangle :public shape
{
public:
	rectangle();
	~rectangle();
	double area();
	void set(double x, double y);
private:
	double a, b;//�����εĳ��Ϳ�
};

rectangle::rectangle()
{
	a = 0;
	b = 0;
	cout << "\t\t\t���ӣ�rectangleĬ�Ϲ��캯��\t" << this << endl;
}

rectangle::~rectangle()
{
	cout << "\t\t\t���ӣ�rectangle��������\t" << this << endl;
}

double rectangle::area()
{
	cout << "\t\t\t���ӣ�rectangle������㺯��\t" << this << endl; //���������أ�
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
		cout << "\t\t\t���ӣ�circle������㺯��\t" << this << endl; //���������أ�
		return 3.14*radius*radius;
	}
private:
	double radius;
};

circle::circle()
	:shape()
{
	radius = 0;
	cout << "\t\t\t���ӣ�circleĬ�Ϲ��캯��\t" << this << endl;
}

circle ::~circle()
{
	cout << "\t\t\t���ӣ�circle��������\t" << this << endl;
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
	cout << "\t\t\t���squareĬ�Ϲ��캯��\t" << this << endl;
}

square::~square()
{
	cout << "\t\t\t���square��������\t" << this << endl;
}

void square::set(double len)
{
	rectangle::set(len, len);
}

int main()
{
	string type;
	cout << "��������״�����";
	cin >> type;
	if (type == "rectangle")
	{
		double x, y;
		rectangle figure;//����������Ķ���
		cout << "��������γ��Ϳ�";
		cin >> x >> y;
		figure.set(x, y);
		cout << "���Ϊ��" << figure.area() << endl;
	}
	else if (type == "square")
	{
		double len;
		square figure;
		cout << "�����������εı߳���";
		cin >> len;
		figure.set(len);
		cout << "���Ϊ��" << figure.area() << endl;
	}
	else if (type == "circle")
	{
		double len;
		circle figure;
		cout << "������Բ�İ뾶��";
		cin >> len;
		figure.set(len);
		cout << "���Ϊ��" << figure.area() << endl;
	}
	return 0;
}