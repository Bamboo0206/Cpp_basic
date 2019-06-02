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

class shape//������
{
public:
	shape();
	shape(const shape& s);
	virtual ~shape();//����������������Ϊ��������������������ʱֻ����shape����������
	virtual double area() = 0;//���麯��
	virtual void set(double x = 0, double y = 0) = 0;
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
	virtual double area()override { return a * b; }
	virtual void set(double x, double y)override;
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
	cout << "\t\t\t���ӣ�circleĬ�Ϲ��캯��\t" << this << endl;
}

circle ::~circle()
{
	cout << "\t\t\t���ӣ�circle��������\t" << this << endl;
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
	cout << "\t\t\t���squareĬ�Ϲ��캯��\t" << this << endl;
}

square::~square()
{
	cout << "\t\t\t���square��������\t" << this << endl;
}

void square::set(double len, double y)
{
	rectangle::set(len, len);
}

void check_cin();//����Ϸ��Լ���

int main()
{
	//shape a;//error �����಻����ʵ����
	shape *figure = NULL;//����ָ��
	string type;
	cout << "��������״�����(rectangle/square/circle)��";
	cin >> type;
	if (type == "rectangle")//string��==���������
	{
		double x, y;
		figure = new rectangle;
		cout << "��������γ��Ϳ�";
		cin >> x >> y;
		check_cin();
		figure->set(x, y);
		cout << "���Ϊ��" << figure->area() << endl;
	}
	else if (type == "square")
	{
		double len;
		figure = new square;
		cout << "�����������εı߳���";
		cin >> len;
		check_cin();
		figure->set(len);
		cout << "���Ϊ��" << figure->area() << endl;
	}
	else if (type == "circle")
	{
		double len;
		figure = new circle;
		cout << "������Բ�İ뾶��";
		cin >> len;
		check_cin();
		figure->set(len);
		cout << "���Ϊ��" << figure->area() << endl;//���õ���rectangle��������㺯��
	}
	else
	{
		cout << "�����ڵ�����" << endl;
	}
	if (figure) delete figure;

	system("pause");
	return 0;
}

void check_cin()//����Ϸ��Լ���
{
	if (!cin)
	{
		cout << "input error��" << endl;
		exit(0);
	}
}
