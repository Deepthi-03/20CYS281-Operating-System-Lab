#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void  *factorial(void *args){
int *n=(void *)args;
int a=1,j,k;
for(j=*n;j>=1;j--){
a=a*j;
}
printf("\nFactorial: %d", a);
}
int main(){

pthread_t thread;
int i;
printf("Enter the value: ");
scanf("%d", &i);
pthread_create(&thread, NULL, factorial,(void *)&i );
pthread_join(thread, NULL);
return 0;
}
