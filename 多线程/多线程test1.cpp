#include <iostream>
#include <thread>
#include<mutex>
#include<Windows.h>

using namespace std;

int k=0;

mutex myMutex;
void output(/*int i*/)
{ 
	/*�̼߳���*/
	lock_guard<mutex> LockGuard(myMutex);//lock_gurad������ʱ��ʼ����������������ʱ���ͷ�����

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
/*��һ��forѭ���ڣ�����4���̷ֱ߳��������0��1��2��3��������ÿ�����ֵ�ĩβ������з���
���thread t(output, i)����һ���߳�t�����߳�����output���ڶ�������i�Ǵ��ݸ�output�Ĳ�����
t�ڴ�����ɺ��Զ�������t.detach��ʾ���߳��ں�̨��������ȴ����߳���ɣ�����ִ�к������䡣*/