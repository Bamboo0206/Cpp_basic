/*（1） 假定有一件商品，程序用随机数指定该商品的价格（1-1000 的整数）；
（2） 提示用户猜价格，并输入：若用户猜的价格比商品价格高或低，对用户作出相应的提示；
（3） 直到猜对为止，并给出提示。
（提示及要求：1，要求使用 C++的输入输出方式（cin, cout），不能使用 C 语言的 printf 等；2，注意检查输入的合法性）*/

#include<iostream>
#include<string>
#include<ios>     // for <streamsize>
#include<limits>  // for numeric_limits
#include<stdexcept> //for runtime_error
using namespace std;

int main()
{
	const int price = 2019;//设定的商品价格
	int guess = 0;
	bool correct = false;
	cerr << "cin.eof():" << cin.eof() << endl
		<< "cin.fail():" << cin.fail() << endl
		<< "cin.bad():" << cin.bad() << endl
		<< "cin.good():" << cin.good() << endl
		<< "*****************" << endl;
	while (!correct)
	{
		cout << "请输入价格:";
		try
		{
			
			if (!(cin >> guess))//cin >> guess外面要加括号，可能是优先级的问题？
			{
				cerr << "cin.eof():" << cin.eof() << endl
					<< "cin.fail():" << cin.fail() << endl
					<< "cin.bad():" << cin.bad() << endl
					<< "cin.good():" << cin.good() << endl;
					//<< "guess=" << guess << endl;//cin错误时guess被置为0
				throw runtime_error("非法输入！");//抛出异常
			}
		}
		catch (runtime_error &err)//捕获runtime_error类型的error
		{
			cerr << err.what() << endl;//不会输出东西？？？
			cin.clear();//使cin有效
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
	return 0;
}