#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void  *fibonacci(void *args){
int *n=(void *)args;
int a[*n],j,sum;
a[0]=0;a[1]=1;
printf("%d\t%d\t", a[0],a[1]);
for(j=2;j<=*n-1;j++){
a[j]=a[j-1]+a[j-2];
printf("%d\t", a[j]);
}
//printf("\nFactorial: %d", a);
}
int main(){

pthread_t thread;
int i;
printf("Enter the number of terms: ");
scanf("%d", &i);
pthread_create(&thread, NULL, fibonacci,(void *)&i );
pthread_join(thread, NULL);
return 0;
}
