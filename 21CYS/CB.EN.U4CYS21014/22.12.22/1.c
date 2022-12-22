#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// printWelcomeMessage will be called when the Thread is created in the main function 
// which takes string as an argument
void *printWelcomeMessage(void *names) {
   sleep(2);
   char *name = (char *)names;
   printf("\n[THREAD] Hello, Welcome %s.", name);
   pthread_exit(NULL);
}

int main () {

   // thread defintion
   pthread_t threads[5];

   // parameter to be passed to the called function - printWelcomeMessage
   char names[10][15] = {"Amritha","Praveen","Saurabh","Sangeetha","Lakshmy","Srinivasan","Ramaguru"};
   int result;

   for(int i = 0; i < 7; i++ ) {
      printf("\n[MAIN] Creating thread, %d", i);

      // Creating the threading and thus calling the function with parameter passed to it
      result = pthread_create(&threads[i], NULL, printWelcomeMessage, (void *)names[i]);

      if (result) {
//here if(result) will be true for any value less than 0. For successful execution result value =0.
         printf("Error in creating thread, %d ", result);
//exit will work for any value less than or equal to 0 =>(exit(0), exit(-1))
         exit(-1);
      }
   }
   // Exit the thread
   pthread_exit(NULL);
}
