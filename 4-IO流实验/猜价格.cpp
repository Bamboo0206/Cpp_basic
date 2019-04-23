/*��1�� �ٶ���һ����Ʒ�������������ָ������Ʒ�ļ۸�1-1000 ����������
��2�� ��ʾ�û��¼۸񣬲����룺���û��µļ۸����Ʒ�۸�߻�ͣ����û�������Ӧ����ʾ��
��3�� ֱ���¶�Ϊֹ����������ʾ��
����ʾ��Ҫ��1��Ҫ��ʹ�� C++�����������ʽ��cin, cout��������ʹ�� C ���Ե� printf �ȣ�2��ע��������ĺϷ��ԣ�*/

#include<iostream>
#include<string>
#include<ios>     // for <streamsize>
#include<limits>  // for numeric_limits
using namespace std;

int main()
{
	const int price = 2019;//�趨����Ʒ�۸�
	int guess = 0;
	bool correct = false;
	while (!correct)
	{
		cout << "������۸�:";
	//����Ϸ�����֤
		char c ;
		c = cin.peek();
		if ((c >= '0') && (c <= '9'))
		{
			cin >> guess;//cin��ȡint����ȡ�߻������е�\n
			c = cin.peek();
			if (!(c == '\n' || c == '\t' || c == ' '))
			{
				printf("input error!\n");
				cin.ignore(numeric_limits<streamsize>::max(), '\n');//�����������з����������е���������
				continue;
			}
			cin.get(c);//�̻س�
		}
		else
		{
			printf("input error!\n");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//�����������з����������е���������
			continue;
			//exit(0);
		}
		
		if (price == guess)
		{
			correct = true;
			cout << "�����ȷ\n";
		}
		else if (price > guess)
		{
			cout << "�²����\n";
		}
		else if (price < guess)
		{
			cout << "�²����\n";
		}
	}
	return 0;
}