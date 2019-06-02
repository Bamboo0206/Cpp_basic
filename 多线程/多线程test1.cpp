#include <iostream>
#include <thread>
#include<mutex>
#include<Windows.h>

using namespace std;

int k=0;

mutex myMutex;
void output(/*int i*/)
{ 
	/*线程加锁*/
	lock_guard<mutex> LockGuard(myMutex);//lock_gurad创建的时候开始加锁，在其析构的时候，释放锁。

	//myMutex.lock();
	cout << ++k
		<< k
		<< k << endl;
	//sleep
	//myMutex.lock();
	//k++;
	//myMutex.unlock();
}

int main()
{

	for (uint8_t i = 0; i < 10; i++)
	{
		thread t(output/*, i*/);
		t.detach();
	}

	getchar();
	return 0;
}
/*在一个for循环内，创建4个线程分别输出数字0、1、2、3，并且在每个数字的末尾输出换行符。
语句thread t(output, i)创建一个线程t，该线程运行output，第二个参数i是传递给output的参数。
t在创建完成后自动启动，t.detach表示该线程在后台允许，无需等待该线程完成，继续执行后面的语句。*/