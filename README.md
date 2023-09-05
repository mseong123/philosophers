# philosophers | 42KL

![philo.gif](https://github.com/mseong123/philosophers/blob/18b304f5b143edcd73791cee300d5e7488ce2cfe/philo.gif)

## Introduction
Philosophers is an individual project at 42 about introduction to the basics of threads, and how multiple threads can work on the same memory space using APIs such as mutexes (mutual exclusion) and semaphores preventing race conditions. Threads are a fundamental concept in modern computing, and they serve several important purposes such as:
- Parallelism - Modern processors often have multiple cores, and threads allow a program to take advantage of these multiple cores to perform tasks concurrently. This can lead to significant performance improvements, especially in tasks that can be divided into smaller, independent subtasks.
- Responsiveness - Threads are also used to improve the responsiveness of applications, particularly in user interfaces. By running time-consuming tasks in separate threads, the main (UI) thread can remain responsive to user input, ensuring a smooth and interactive user experience.

In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.

It was originally formulated in 1965 by Edsger Dijkstra as a student exam exercise, presented in terms of computers competing for access to tape drive peripherals. Soon after, Tony Hoare gave the problem its present formulation

[Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

## Project scope
The scope of the project is summarised in the [pdf file](https://github.com/mseong123/philosophers/blob/bccaeeb0420a088ddb46ab2409eec01dcd0d38c8/en.subject.pdf).  To summarise, each philosopher's job is to eat, sleep and think in that order (and continue in perpetuity until somebody dies). In order to eat, the philosopher has to hold 2 forks and there is only 1 fork available for each philosopher in the program. Hence for N number of philosophers, some will have access to 2 forks and can eat and some will have to wait for their turn until another philosopher finishes eating and put down his respective fork. If a philosopher doesn't eat within a set time, he will die and program will end. We will have to implement our threading APIs including mutexes and semaphores to simulate these conditions. 

<img src="https://github.com/mseong123/philosophers/blob/9bc6ff655e86bca7934cbea02cd4ef25df0769c6/philo_dining_table.png" alt="philo dining table" title="philo dining table" width="300px">

## Status

Validated 23/6/2023. Grade: 125%. Project duration: 1 week.

## Clone and Compile (for mandatory)

```
git clone https://github.com/mseong123/philosophers.git
cd philosophers
cd philo
make
```

## Run (for mandatory)
To run the program:

```
./philo <no of philosophers> <time to die in millisecond> <time to eat in millisecond> <time to sleep in millisecond>
```

Scenarios

**Scenario 1**
```
./philo 5 800 200 200
```
There's 5 philosophers and given time of 800 millisecond(time to die for each philo) 200 millisecond(time to eat for each philo) and 200 millisecond(time to sleep for each philo), no philosophers will(should) die. 

**Scenario 2**
```
./philo 4 310 200 100
```
There's 4 philosophers and given time of 310 millisecond(time to die for each philo) 200 millisecond(time to eat for each philo) and 100 millisecond(time to sleep for each philo), 1 philosopher WILL (SHOULD) DIE.

Any types of scenario can be simulated and experimented by amending the arguments above.

## To run bonus
```
cd ..
cd philo_bonus
make
./philo_bonus <same arguments as mandatory above>
```
For bonus, the philosopher problem is simulated using processes instead of threads using C system calls (forks) and relevant APIs. Since processes doesn't have shared memory, semaphores are used in place of mutexes to prevent race conditions.

## Resources
General thread understanding:  
[Introduction to threads (pthreads) | C programming](https://www.youtube.com/watch?v=ldJ8WGZVXZk)  
[How to create and join threads in C (pthreads)](https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM)
[What are race conditions](https://www.youtube.com/watch?v=FY9livorrJI)  

Threads vs. Processes:  
[Difference between process and thread](https://www.geeksforgeeks.org/difference-between-process-and-thread/)  

Mutex:  
[What is a mutex in C? (pthread_mutex)](https://www.youtube.com/watch?v=oq29KUy29iQ)  
[Mutex lock for Linux Thread Synchronization](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/) 

General semaphore understanding:  
[Semaphores in Process Synchronization](https://www.geeksforgeeks.org/semaphores-in-process-synchronization/)  
[How to use POSIX semaphores in C language](https://www.geeksforgeeks.org/use-posix-semaphores-c/)  
