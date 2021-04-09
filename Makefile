all: toss toss_cpp

toss_cpp: toss_cpp.o
	g++ -o toss_cpp -g toss_cpp.o -pthread
	
toss_cpp.o: toss_cpp.cpp	
	g++ -g -c -Wall -std=c++17 toss_cpp.cpp 

toss: toss.o
	gcc -o toss -g toss.o -pthread

toss.o: toss.c 
	gcc -g -c -Wall toss.c

clean:
	rm -f *.o toss toss_cpp
