/*��1�� �ٶ���һ����Ʒ�������������ָ������Ʒ�ļ۸�1-1000 ����������
��2�� ��ʾ�û��¼۸񣬲����룺���û��µļ۸����Ʒ�۸�߻�ͣ����û�������Ӧ����ʾ��
��3�� ֱ���¶�Ϊֹ����������ʾ��
����ʾ��Ҫ��1��Ҫ��ʹ�� C++�����������ʽ��cin, cout��������ʹ�� C ���Ե� printf �ȣ�2��ע��������ĺϷ��ԣ�*/

#include<iostream>
#include<string>
#include<ios>     // for <streamsize>
#include<limits>  // for numeric_limits
#include<stdexcept> //for runtime_error
#include<ctime>

using namespace std;
#define DEBUG 1 //��Ϊ1�����������Ϣ

int main()
{
	srand((unsigned int)time(NULL));
	int price = rand() % 1000;//�趨����Ʒ�۸�
	price++;
	int guess = 0;
	bool correct = false;
	if(DEBUG)
	cerr << "cin.eof():" << cin.eof() << endl
		<< "cin.fail():" << cin.fail() << endl
		<< "cin.bad():" << cin.bad() << endl
		<< "cin.good():" << cin.good() << endl
		<< "*****************" << endl;
	while (!correct)
	{
		cout << "������۸�:";
		try/*�쳣����*/
		{
			/*�������Ϸ���*/
			if (!(cin >> guess))//basic_ios����������غ���operator void *() const �� bool operator!() constʹ�����������Ϊ�ж��������ݡ�
			{
				if(DEBUG)
					/*��ӡ������Ϣ*/
				cerr << "cin.eof():" << cin.eof() << endl
					<< "cin.fail():" << cin.fail() << endl
					<< "cin.bad():" << cin.bad() << endl
					<< "cin.good():" << cin.good() << endl;
				throw runtime_error("�Ƿ����룡");//���벻�Ϸ����׳��쳣
			}
		}
		/*�쳣����*/
		catch (runtime_error &err)//����runtime_error���͵�error
		{
			cerr << err.what() << endl;
			cin.clear();//ʹcin��Ч
			if (DEBUG)
			cerr << "***��ʹ��cin.clear()***\n"
				<< "cin.eof():" << cin.eof() << endl
				<< "cin.fail():" << cin.fail() << endl
				<< "cin.bad():" << cin.bad() << endl
				<< "cin.good():" << cin.good() << endl
				//<< "guess=" << guess << endl
				<< "************************" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//�����������з����������е���������
			continue;
		}

		/*�������Ϸ�����Ƚϴ�С*/
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

	system("pause");
	return 0;
}