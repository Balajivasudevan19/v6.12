#include<stdio.h>
#include<pthread.h>
void*even_fun(void*arg)
{
	int*b=(int*)arg;
	printf("%d\n",b[0]);
	for(int i=0;i<9;i++){
		if(b[i]%2==0)
			printf("even:%d\n",b[i]);
	}
}
void*odd_fun(void*arg)
{
 int*c=(int*)arg;
 for(int i=0;c[i];i++)
 {
	 if(c[i]%2!=0)
		 printf("odd:%d\n",c[i]);
 }
}
int main()
{
	int a[]={1,2,3,4,5,6,7,8,9};
	pthread_t even1,odd1;
	pthread_create(&even1,NULL,even_fun,(void*)a);
	pthread_create(&odd1,NULL,odd_fun,(void*)a);
	pthread_join(even1,NULL);
	pthread_join(odd1,NULL);
}
