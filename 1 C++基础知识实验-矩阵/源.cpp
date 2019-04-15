/*��1���ٶ������СΪ 4��5�����ͣ���
��2�� ����ռ���� new ��̬���룬������ָ���У�
��3�� ��������ʼ�����������Դ� cin���������Ԫ��
��4�� ��������������������ʽ���� cout ��
��5�� ���������ӵĺ�����ʵ������������ӹ��ܣ������������һ�������У�
��6�� �����������ĺ�����ʵ����������������ܣ������������һ�������У�
��7�� ��̬������������  A1 ��A2 ��A3 ��
��8�� ��ʼ�� A1 ��A2 ��
��9�� ���㲢��� A3=A1+A2, A3=A1-A2
��10�� �ͷž���ռ䡣 */

#include<iostream>
using namespace std;

void Delete_Matrix(int (*pMatrix)[5]);//��10�� �ͷž���ռ䡣
void Init_Matrix(int (*pMatrix)[5]);//��3�� ��������ʼ�����������Դ� cin���������Ԫ��
void Output(int (*pMatrix)[5]);//��4�� ��������������������ʽ���� cout ��
void Add_Matrix(int (*M1)[5], int (*M2)[5], int (*M3)[5]);//��5�� ���������ӵĺ�����ʵ������������ӹ��ܣ���������ڣ�M3�������У�
void Sub_Matrix(int (*M1)[5], int (*M2)[5], int (*M3)[5]);//��6�� �����������ĺ�����ʵ�����������������(M1-M2)�������������һ������(M3)�У�



int main()
{
	/*��7�� ��̬������������  A1 ��A2 ��A3 ��*/
	// Ԫ������Ϊ��int[5]�������飬�ɸ�ֵ����int[5]�����͵�ָ��.  
	int(*A1)[5] = new int[4][5];
	int(*A2)[5] = new int[4][5];
	int(*A3)[5] = new int[4][5];


	/*��8�� ��ʼ�� A1 ��A2 ��*/
	cout << "������4x5����������A1:" << endl;
	Init_Matrix(A1);
	cout << "������4x5����������A2:" << endl;
	Init_Matrix(A2);

	//��9�� ���㲢��� A3 = A1 + A2, A3 = A1 - A2
	cout << "A1 + A2:" << endl;
	Add_Matrix(A1, A2, A3);
	Output(A3);

	cout << "A1 - A2:" << endl;
	Sub_Matrix(A1, A2, A3);
	Output(A3);

	//��10�� �ͷž���ռ䡣
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

//��5�� ���������ӵĺ�����ʵ������������ӹ��ܣ���������ڣ�M3�������У� 
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

//��6�� �����������ĺ�����ʵ�����������������(M1-M2)�������������һ������(M3)�У�
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