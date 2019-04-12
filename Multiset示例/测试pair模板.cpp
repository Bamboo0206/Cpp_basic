//pair是个结构 详细见onenote-》c++-》STL-》006
//https://docs.microsoft.com/zh-cn/cpp/standard-library/pair-structure?view=vs-2019
#include <iostream>
#include <set> //使用multiset须包含此文件
using namespace std;
int fun()
{
	pair<int, float> object(pair<double, char*>(2.33, "hello world"));//char*不能转换到float

	pair < string, int > k1(pair < char*, double >("this", 4.5));//为什么报错？？？简直玄学    难道char*不能转string？
	pair < char*, int > k2(pair < string, double >("this", 4.5));//????
	pair < string, int > k3(pair < string, double >("this", 4.5));//string类是不是没把this字符串放在常量区？所以不报错？好像不是？？？
	pair < char*, int > k4(pair < char*, double >("this", 4.5));

	char s[5];
	s[0] = 'a'; s[1] = 'b'; s[2] = '\0';//一个非常量字符串
	pair < char*, int > k5(pair < char*, double >(s, 4.5));// 我知道了！！应该是常量字符串的锅
	pair < string, int > k6(pair < char*, double >(s, 4.5));//好了 嘻嘻

	pair<int, int> p(pair<double, double>(5.5, 4.6));
	pair < string, int > x(pair < double, int > b(3.4, 100));//不能写b，而且double不能转换到int
	pair<int, int> obj(pair<char, float>('c', 2.33));
}