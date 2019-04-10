#include<iostream>
#include<iterator>
using namespace std;

class MyLess {//函数对象类
public:    
	bool operator() (int a1, int a2) 
	{ 
		if ((a1 % 10) < (a2 % 10)) 
			return true; 
		else return false; 
	}
};

bool MyCompare(int a1, int a2)//全局函数
{ 
	if ((a1 % 10) < (a2 % 10))
		return false; 
	else 
		return true; 
}

template <class iterator, typename Pred>
iterator MyMax(iterator it_first, iterator it_last, Pred myless)
{
	iterator Max=it_first;
	for (; it_first != it_last; ++it_first)
	{
		if (myless(*Max, *it_first))
			Max = it_first;
	}
	return Max;
}


int main() 
{ 
	int a[] = { 35,7,13,19,12 }; 
	cout << *MyMax(a, a + 5, MyLess()) << endl; 
	cout << *MyMax(a, a + 5, MyCompare) << endl;
	return 0; 
}
