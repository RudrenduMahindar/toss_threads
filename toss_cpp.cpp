#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

#define MAX_SUM 10

//using namespace std;

std::mutex m;
std::condition_variable add_cv, serve_cv;
//condition_variable cv;
//condition_variable serve_cv;

bool add_data = true;
int sum = 0;

void add()
{
	while(1)
	{
		std::unique_lock<std::mutex> u1(m); // calling contructor starts critical section, locks mutex
		add_cv.wait(u1, [](){return (add_data == true); }); //wait until add_data is true
		sum += 1;

		if(sum > MAX_SUM)
		{
			add_data = false; //reset flag
			serve_cv.notify_all();
			break;
		}

		std::cout<< "I am inside add thread with sum = " << sum << "\n";
		add_data = false; //reset flag
		serve_cv.notify_all();
	}

}


void serve()
{
	while(1)
	{
		std::unique_lock<std::mutex> u1(m); // calling contructor starts critical section, locks mutex
		serve_cv.wait(u1, []() {return (add_data == false); }); //wait in serve_cv until add_data is false (opposite of add())

		if(sum > MAX_SUM)
		{
			break;
		}
		sum += 1;
		std::cout<< "I am inside serve thread with sum = " << sum << "\n";
		add_data = true; //reset flag for add thread
		add_cv.notify_all();
	}

}


int main()
{
	std::thread t1(add);
	std::thread t2(serve);
	t1.join();
	t2.join();
	return 0;	
}