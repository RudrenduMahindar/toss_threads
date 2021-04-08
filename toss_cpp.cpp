#include <iostream>
#include <fstream>
#include <future>
#include <string>
#include <queue>
#include <vector>
#include <mutex>
#include <thread>

using namespace std;

mutex m;
condition_variable add_cv;
condition_variable serve_cv;

bool add_data = true;
int sum = 0;

void add()
{
	

}


void serve()
{
	

}


int main()
{
	thread t1(add);
	thread t2(serve);
	t1.join();
	t2.join();
	return 0;	

}