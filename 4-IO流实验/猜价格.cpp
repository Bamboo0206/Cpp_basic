/*（1） 假定有一件商品，程序用随机数指定该商品的价格（1-1000 的整数）；
（2） 提示用户猜价格，并输入：若用户猜的价格比商品价格高或低，对用户作出相应的提示；
（3） 直到猜对为止，并给出提示。
（提示及要求：1，要求使用 C++的输入输出方式（cin, cout），不能使用 C 语言的 printf 等；2，注意检查输入的合法性）*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	const int price = 2019;//设定的商品价格
	int guess = 0;
	bool correct = false;
	while (!correct)
	{
		cout << "请输入价格:";
		cin >> guess;//待改 输入合法性验证
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