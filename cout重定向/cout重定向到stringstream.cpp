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
	streambuf* buffer = cout.rdbuf(); //oldbuffer,STDOUT的缓冲区 //用于恢复标准输入流

	cout.rdbuf(ss.rdbuf());//输出重定向到stringstream
	cout << 123 << 456 << 789;
	fun();//其他函数里的cout也会被改
	string s(ss.str());
	//cout <<"s="<< s << endl;//这句是不会打印到屏幕上的，因为cout重定向了

	cout.rdbuf(buffer); //重新载入STDOUT的缓冲区
	cout << "标准输出流:";
	cout <<"s="<< s << endl;//打印字符串

	/*输入重定向*/
	stringstream iss;
	streambuf* ibuffer = cin.rdbuf();
	cin.rdbuf(iss.rdbuf());//重定向

	string istr = "abcd\nefg\nhijk\nlmn\n\0";
	iss.str(istr);
	string temp;
	iss >> temp;//读到\n停止，但不取走\n
	cout << temp;
	
	char c[500];
	iss.getline(c, 500, '\0');
	cout << c;

	cin.rdbuf(ibuffer);
	cout << "请从键盘输入：";
	cin >> temp;
	cout <<"回显"<< temp;


	return 0;
}