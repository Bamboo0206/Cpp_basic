/*2.2 编写C++程序完成“矩阵”类以下功能：
（1） 用类来实现矩阵，定义一个矩阵的类，属性包括：
 矩阵大小，用 lines, rows（行、列来表示）；
 存贮矩阵的数组指针，根据矩阵大小动态申请（new）。
（2） 矩阵类的方法包括：
 构造函数，参数是矩阵大小，需要动态申请存贮矩阵的数组；
 析构函数，需要释放矩阵的数组指针；
 拷贝构造函数，需要申请和复制数组；
 输入，可以从 cin 中输入矩阵元素；
 输出，将矩阵格式化输出到 cout；
 矩阵相加的函数，实现两个矩阵相加的功能，结果保存在另一个矩阵类，但必须矩阵大小相同；
 矩阵相减的函数，实现两个矩阵相减的功能，结果保存在另一个矩阵类，但必须矩阵大小相同。
*/

#include<iostream>
using namespace std;

class Matrix {
	/* 矩阵大小，用 lines, rows（行、列来表示）；
 存贮矩阵的数组指针，根据矩阵大小动态申请（new）。*/
private:
	int line, row;//矩阵大小，用 lines, rows（行、列来表示）；
	int **matrix;

public:
	Matrix();
	Matrix(int row, int col);
	Matrix(Matrix &m);
	Matrix& operator=(const Matrix &m);
	~Matrix();//析构函数
	void input();
	void output();
	void add(Matrix &M1, Matrix &M2);
	void sub(Matrix &M1, Matrix &M2);
};

Matrix::Matrix()
{
	line = 0;
	row = 0;
	matrix = NULL;
}

Matrix::Matrix(int line, int row)//有参构造函数
{
	this->line = line;
	this->row = row;
	matrix = new int*[line];
	for (int i=0; i < line; i++)
		matrix[i] = new int[row];
	cout << "\t\tMatrix有参构造函数called！" << this << endl;
}

/*拷贝构造函数，需要申请和复制数组；*/
Matrix::Matrix(Matrix & m)//拷贝构造函数
{
	line = m.line;
	row = m.row;
	/*深拷贝，新分配资源*/
	matrix = new int*[line];
	for (int i=0; i < line; i++)
		matrix[i] = new int[row];
	for (int i = 0; i < line; i++)
	{
		for (int j =0; j < row; j++)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
	cout << "\t\tMatrix深拷贝构造函数called！" << this << endl;
}

Matrix & Matrix::operator=(const Matrix & m)//赋值运算符重载函数
{
	if (this == &m) return *this;
	line = m.line;
	row = m.row;

	/*新分配资源*/
	if (this->matrix != NULL) 
	{
		for (int i=0; i < row; i++)
			delete[]matrix[i];
		delete[]matrix;
	}
	matrix = new int*[line];
	for (int i = 0; i < line; i++)
		matrix[i] = new int[row];
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < row; j++) 
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
	cout << "\t\tMatrix赋值运算符重载函数called！" << this << endl;
	return *this;
}

Matrix::~Matrix()
{
	for (int i=0; i < line; i++)
		delete[](matrix[i]);
	delete[]matrix;
	cout << "\t\tMatrix析构函数called！" << this << endl;
}

void Matrix::input()
{
	cout << "\t\tintput函数called！" << this << endl;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cin >> matrix[i][j];
			//cout << "called！";
		}
	}
}

void Matrix::output()
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

/*矩阵相加的函数，实现矩阵M1 M2相加的功能，结果保存在this，但必须矩阵大小相同；*/
void Matrix::add(Matrix &M1, Matrix &M2)
{
	if ((M1.line != M2.line) || (M2.line != this->line)
		|| (M1.row != M2.row) || (M2.row != this->row))
	{
		cout << "矩阵大小不相同！\n";
		return;
	}
	for (int i = 0; i < M1.line; i++)
	{
		for (int j = 0; j < M1.row; j++)
		{
			this->matrix[i][j] = M1.matrix[i][j] + M2.matrix[i][j];
		}
	}
}

void Matrix::sub(Matrix &M1, Matrix &M2)//矩阵M1-M2，存在this中
{
	if ((M1.line != M2.line) || (M2.line != this->line)
		|| (M1.row != M2.row) || (M2.row != this->row))
	{
		cout << "矩阵大小不相同！\n";
		return;
	}
	for (int i = 0; i < M1.line; i++)
	{
		for (int j = 0; j < M1.row; j++)
		{
			this->matrix[i][j] = M1.matrix[i][j] - M2.matrix[i][j];
		}
	}
}



int main()
{
	/*（3） 定义三个矩阵：A1、A2、A3；
（4） 初始化 A1、A2；
（5） 计算并输出 A3 = A1 加 A2，A3=A1 减 A2；
（要求及提示：最好能实现对赋值操作符“=”的重载；注意检查“自赋值”、释放“旧元素”）*/
	int line, row;
	cout << "请输入矩阵M1的行数和列数：\n";
	cin >> line >> row;
	Matrix M1(line, row);
	cout << "请输入矩阵M2的行数和列数：\n";
	cin >> line >> row;
	Matrix M2(line, row);
	cout << "请输入矩阵M3的行数和列数：\n";
	cin >> line >> row;
	Matrix M3(line, row);

	cout << "请输入矩阵M1的元素：\n";
	M1.input();
	cout << "请输入矩阵M2的元素：\n";
	M2.input();

	cout << "\nM1+M2=\n";
	M3.add(M1, M2);
	M3.output();
	cout << "\nM1-M2=\n";
	M3.sub(M1, M2);
	M3.output();

/*（要求及提示：最好能实现对赋值操作符“=”的重载；注意检查“自赋值”、释放“旧元素”）
（6） 用 new 动态创建三个矩阵类的对象：pA1、pA1、pA3；
（7） 初始化 pA1、pA2；
（8） 计算并输出 pA3=pA1 加 pA2，pA3=pA1 减 pA2；
（9） 释放 pA1、pA2、pA3。*/
	Matrix *pA1 , *pA2, *pA3;
	//cout << "请输入矩阵A1的行数和列数：\n";
	//cin >> line >> row;
	//pA1=new Matrix(line, row);
	//cout << "请输入矩阵A2的行数和列数：\n";
	//cin >> line >> row;
	//pA2 = new Matrix(line, row);
	//cout << "请输入矩阵A3的行数和列数：\n";
	//cin >> line >> row;
	//pA3 = new Matrix(line, row);

	pA1 = new Matrix(M1);//使用深拷贝构造函数
	pA2 = new Matrix;
	*pA2 = M2;//赋值运算符重载
	pA3 = new Matrix(M1);

	//cout << "请输入矩阵A1的元素：\n";
	//pA1->input();
	//cout << "请输入矩阵A2的元素：\n";
	//pA2->input();

	cout << "\nA1+A2=\n";
	pA3->add(M1, M2);
	pA3->output();
	cout << "\nA1-A2=\n";
	pA3->sub(M1, M2);
	pA3->output();

	delete pA1;//调用析构函数
	delete pA2;
	delete pA3;
	cout << "end!\n";

	system("pause");
	return 0;
	/*在return 0前自动调用析构函数，先定义的后析构*/
}