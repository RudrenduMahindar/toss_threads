
# toss_threads
This repo contains files to show the toss of actions between two threads (alternatively) by using mutex and condition variables. 
Toss of actions is like a behaviour:

"Thread 1 says hi"-->>thread 1


"Thread 2 says hello"-->>thread 2


The two threads work alternatively to accomplish the goal.

Platform used: 32-bit Ubuntu 16.04.6
(The main branch of this repo contains C, C++17 code, branch1 contains C code, branch2 contains C, C++17 code)


# How to use the code?

Step 1: Clone the repo, let's say that you cloned the repo in `~/home/codes` 

Step 2: Browse to the directory of the cloned repo and type: `cd toss_threads`, now your path is `~/home/codes/toss_threads` 

Step 3: Run the code: type: `make all` ; to run the executable for C code type: `./toss` ; to run the executable for C++17 code type: `./toss_cpp`

Enjoy the toss!!!!!!
