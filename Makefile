toss:	toss.o
	gcc -o toss -g toss.o -pthread

toss.o: toss.c 
	gcc -g -c -Wall toss.c


clean:
	rm -f *.o toss
