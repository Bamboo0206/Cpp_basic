#include <sstream>
#include <iostream>
#include <string>
using namespace std;
void fun()
{
	cout << "xxx";
}
int main()
{
	stringstream ss;
	streambuf* buffer = cout.rdbuf(); //oldbuffer,STDOUT�Ļ����� //���ڻָ���׼������

	cout.rdbuf(ss.rdbuf());//����ض���stringstream
	cout << 123 << 456 << 789;
	fun();//�����������coutҲ�ᱻ��
	string s(ss.str());
	//cout <<"s="<< s << endl;//����ǲ����ӡ����Ļ�ϵģ���Ϊcout�ض�����

	cout.rdbuf(buffer); //��������STDOUT�Ļ�����
	cout << "��׼�����:";
	cout <<"s="<< s << endl;//��ӡ�ַ���

	/*�����ض���*/
	stringstream iss;
	streambuf* ibuffer = cin.rdbuf();
	cin.rdbuf(iss.rdbuf());//�ض���

	string istr = "abcd\nefg\nhijk\nlmn\n\0";
	iss.str(istr);
	string temp;
	iss >> temp;//����\nֹͣ������ȡ��\n
	cout << temp;
	
	char c[500];
	iss.getline(c, 500, '\0');
	cout << c;

	cin.rdbuf(ibuffer);
	cout << "��Ӽ������룺";
	cin >> temp;
	cout <<"����"<< temp;


	return 0;
}