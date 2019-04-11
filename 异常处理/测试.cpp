#include<iostream>
using namespace std;
int main()
{
	try 
	{
		/*代码*/
		/*出现错误：*/
		throw 对象 / 数据;
	}
	catch (参数)//不允许大部分实参到形参的强制类型转换
	{
		try{}//允许嵌套
		catch (){}
	}
	catch (参数)
	{
		/*处理*/
		/*再抛出错误*/
		throw;//抛向更外层（调用它的函数？）
	}
	catch (...)//接住所有类型错误
	{

	}
}