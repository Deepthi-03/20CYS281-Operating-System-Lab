/*two types of multitasking 
1. process based multitasking - concurrent execution of programs.
2. thread based multitasking - concurrent execution of parts of same program.

=>thread is like smaller unit of a process which is running inside the process.
=>"program" can ne either a thread or a process.
=>by default c lang doesn't support threading, hence we import a library pthread.h defined by a body called POSIX
=>thread funtions are always accessed using pointer values because every thread has a different address and all these 
threads may work concurrently. So, if we call by function name the concurrent working may get affected coz the process 
may leave the previous work and get assigned to new function.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void  *printMsg(void *args){
printf("Hello!");
pthread_exit(NULL);
}
int main(){

pthread_t thread; //A thread id is getting assigned

printf("%ld\n", (long)&thread); // thread id is of "long int" type. variable "thread" contains the thread_id.  thread id is also a pointer, so to print the value we have to use &.
//(long) is type casting it to long from long int. 
pthread_create(&thread, NULL, printMsg, NULL);
pthread_join(thread, NULL);
//pthread_exit(NULL); //without giving this exit statement, the thread will not print anything. But giving exit is not the exact right way. pthread_join() is a proper way to exit a threa
return 0;
}
