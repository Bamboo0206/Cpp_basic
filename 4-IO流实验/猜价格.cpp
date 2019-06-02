/*（1） 假定有一件商品，程序用随机数指定该商品的价格（1-1000 的整数）；
（2） 提示用户猜价格，并输入：若用户猜的价格比商品价格高或低，对用户作出相应的提示；
（3） 直到猜对为止，并给出提示。
（提示及要求：1，要求使用 C++的输入输出方式（cin, cout），不能使用 C 语言的 printf 等；2，注意检查输入的合法性）*/

#include<iostream>
#include<string>
#include<ios>     // for <streamsize>
#include<limits>  // for numeric_limits
#include<ctime>
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	int price = rand()%1000;//设定的商品价格
	price++;
	int guess = 0;
	bool correct = false;
	while (!correct)
	{
		cout << "请输入价格:";
	//输入合法性验证
		char c ;
		c = cin.peek();
		if ((c >= '0') && (c <= '9'))
		{
			cin >> guess;//cin读取int不会取走缓冲区中的\n
			c = cin.peek();
			if (!(c == '\n' || c == '\t' || c == ' '))
			{
				printf("input error!\n");
				cin.ignore(numeric_limits<streamsize>::max(), '\n');//放弃包含换行符的输入流中的所有内容
				continue;
			}
			cin.get(c);//吞回车
		}
		else
		{
			printf("input error!\n");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//放弃包含换行符的输入流中的所有内容
			continue;
			//exit(0);
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

	system("pause");
	return 0;
}