//Addition program using multiple threads and user inputs
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
struct parameter{
int a;
int b;
};

void addition(void *args){ // if we give void *addition then while passing the parameter in line 33, addition, &p is enough.
//strct parameter *z = (struct parameter *)args;  ==>THis is type casting.
struct parameter *z = args; //Type casting is not required always. But it is better to remember it and write it in every program. 
int c;
c=z->a + z->b;
printf("\n%d + %d = %d", z->a,z->b,c);
pthread_exit(NULL);//Don't forget to use this exit statement while using multiple threads
}
int main () {

   struct parameter p[5];
   // thread defintion
   pthread_t threads[5];
   int result;
   int i;
   for(int i = 0; i < 5; i++ ) {
   sleep(1);
      printf("\n[MAIN] Creating thread, %d\n", i);
	  printf("Enter the numbers to add: \n");
	  scanf("%d %d", &p[i].a, &p[i].b);


      // Creating the threading and thus calling the function with parameter passed to it
      result = pthread_create(&threads[0], NULL, (void *)addition, &p[i]);// we can either give (void *)&p or just &p
		}
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
