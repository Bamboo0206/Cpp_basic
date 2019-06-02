/*（1） 假定有一件商品，程序用随机数指定该商品的价格（1-1000 的整数）；
（2） 提示用户猜价格，并输入：若用户猜的价格比商品价格高或低，对用户作出相应的提示；
（3） 直到猜对为止，并给出提示。
（提示及要求：1，要求使用 C++的输入输出方式（cin, cout），不能使用 C 语言的 printf 等；2，注意检查输入的合法性）*/

#include<iostream>
#include<string>
#include<ios>     // for <streamsize>
#include<limits>  // for numeric_limits
#include<stdexcept> //for runtime_error
#include<ctime>

using namespace std;
#define DEBUG 1 //设为1则输出调试信息

int main()
{
	srand((unsigned int)time(NULL));
	int price = rand() % 1000;//设定的商品价格
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
		cout << "请输入价格:";
		try/*异常处理*/
		{
			/*检查输入合法性*/
			if (!(cin >> guess))//basic_ios的运算符重载函数operator void *() const 和 bool operator!() const使得流对象可作为判断语句的内容。
			{
				if(DEBUG)
					/*打印调试信息*/
				cerr << "cin.eof():" << cin.eof() << endl
					<< "cin.fail():" << cin.fail() << endl
					<< "cin.bad():" << cin.bad() << endl
					<< "cin.good():" << cin.good() << endl;
				throw runtime_error("非法输入！");//输入不合法，抛出异常
			}
		}
		/*异常处理*/
		catch (runtime_error &err)//捕获runtime_error类型的error
		{
			cerr << err.what() << endl;
			cin.clear();//使cin有效
			if (DEBUG)
			cerr << "***已使用cin.clear()***\n"
				<< "cin.eof():" << cin.eof() << endl
				<< "cin.fail():" << cin.fail() << endl
				<< "cin.bad():" << cin.bad() << endl
				<< "cin.good():" << cin.good() << endl
				//<< "guess=" << guess << endl
				<< "************************" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//放弃包含换行符的输入流中的所有内容
			continue;
		}

		/*如果输入合法，则比较大小*/
		if (price == guess)
		{
			correct = true;
			cout << "结果正确\n";
		}
		else if (price > guess)
		{
			cout << "猜测过低\n";
		}
		else if (price < guess)
		{
			cout << "猜测过高\n";
		}
	}

	system("pause");
	return 0;
}