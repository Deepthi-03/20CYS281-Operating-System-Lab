//Addition program using threads
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
struct parameter{
int a;
int b;
};

void *addition(void *args){

struct parameter *z = args;
int c;
c=z->a + z->b;
printf("c=%d", c);

}
int main () {

   struct parameter p;
   p.a = 10;
   p.b = 20;
   // thread defintion
   pthread_t threads[5];
   int result;
    int i;
  // for(int i = 0; i < 7; i++ ) {
      printf("\n[MAIN] Creating thread, %d", i);

      // Creating the threading and thus calling the function with parameter passed to it
      result = pthread_create(&threads[0], NULL, addition, (void *)&p);

      if (result) {
//here if(result) will be true for any value less than 0. For successful execution result value =0.
         printf("Error in creating thread, %d ", result);
//exit will work for any value less than or equal to 0 =>(exit(0), exit(-1))
         exit(-1);
    //  }
   }
   // Exit the thread
   pthread_exit(NULL);
}
