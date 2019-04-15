/*（1）假定矩阵大小为 4×5（整型）；
（2） 矩阵空间采用 new 动态申请，保存在指针中；
（3） 定义矩阵初始化函数，可以从 cin中输入矩阵元素
（4） 定义矩阵输出函数，将格式化到 cout ；
（5） 定义矩阵相加的函数，实现两个矩阵相加功能，结果保存在另一个矩阵中；
（6） 定义矩阵相减的函数，实现两个矩阵相减功能，结果保存在另一个矩阵中；
（7） 动态申请三个矩阵：  A1 、A2 、A3 ；
（8） 初始化 A1 、A2 ；
（9） 计算并输出 A3=A1+A2, A3=A1-A2
（10） 释放矩阵空间。 */

#include<iostream>
using namespace std;

void Delete_Matrix(int (*pMatrix)[5]);//（10） 释放矩阵空间。
void Init_Matrix(int (*pMatrix)[5]);//（3） 定义矩阵初始化函数，可以从 cin中输入矩阵元素
void Output(int (*pMatrix)[5]);//（4） 定义矩阵输出函数，将格式化到 cout ；
void Add_Matrix(int (*M1)[5], int (*M2)[5], int (*M3)[5]);//（5） 定义矩阵相加的函数，实现两个矩阵相加功能，结果保存在（M3）矩阵中；
void Sub_Matrix(int (*M1)[5], int (*M2)[5], int (*M3)[5]);//（6） 定义矩阵相减的函数，实现两个矩阵相减功能(M1-M2)，结果保存在另一个矩阵(M3)中；



int main()
{
	/*（7） 动态申请三个矩阵：  A1 、A2 、A3 ；*/
	// 元素类型为‘int[5]’的数组，可赋值给‘int[5]’类型的指针.  
	int(*A1)[5] = new int[4][5];
	int(*A2)[5] = new int[4][5];
	int(*A3)[5] = new int[4][5];


	/*（8） 初始化 A1 、A2 ；*/
	cout << "请输入4x5的整数矩阵A1:" << endl;
	Init_Matrix(A1);
	cout << "请输入4x5的整数矩阵A2:" << endl;
	Init_Matrix(A2);

	//（9） 计算并输出 A3 = A1 + A2, A3 = A1 - A2
	cout << "A1 + A2:" << endl;
	Add_Matrix(A1, A2, A3);
	Output(A3);

	cout << "A1 - A2:" << endl;
	Sub_Matrix(A1, A2, A3);
	Output(A3);

	//（10） 释放矩阵空间。
	Delete_Matrix(A1);
	Delete_Matrix(A2);
	Delete_Matrix(A3);

	return 0;
}

void Delete_Matrix(int (*pMatrix)[5])
{
		delete[]pMatrix;
}

void Init_Matrix(int(*pMatrix)[5])
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			cin >> pMatrix[row][col];
		}
	}
}

void Output(int(*pMatrix)[5])
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			cout << pMatrix[row][col] << ' ';
		}
		cout << endl;
	}
}

//（5） 定义矩阵相加的函数，实现两个矩阵相加功能，结果保存在（M3）矩阵中； 
void Add_Matrix(int (*M1)[5], int (*M2)[5], int (*M3)[5])
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			M3[row][col] = M2[row][col] + M1[row][col];
		}
	}
}

//（6） 定义矩阵相减的函数，实现两个矩阵相减功能(M1-M2)，结果保存在另一个矩阵(M3)中；
void Sub_Matrix(int (*M1)[5], int (*M2)[5], int (*M3)[5])
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			M3[row][col] = M1[row][col] - M2[row][col];
		}
	}
}