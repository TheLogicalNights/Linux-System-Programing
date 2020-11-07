/*
	Problem Statement : Write a program which creates two threads and demonstrate the working of multithreading.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * fun(void *p)
{
	int i = 0;
	printf("Inside fun thread....\n");
	for(i=0;i<=(int)p;i++)
	{
		printf("fun : %d\n",i);
	}
	pthread_exit(NULL);
}
void * gun(void *p)
{
	int i = 0;
	printf("Inside gun thread....\n");
	for(i=0;i<=(int)p;i++)
	{
		printf("gun : %d\n",i);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	int iRet = 0;
	int iRet1 = 0;
	int iNo1 = 1000;
	int iNo2 = 2000;
	
	printf("Inside main thread....\n");
	
	iRet = pthread_create(&thread1,NULL,fun,(void *)iNo1);
	if(iRet != 0)
	{
		printf("Error : Unable to create fun thread...\n");
		return -1;
	}
	iRet1 = pthread_create(&thread2,NULL,gun,(void *)iNo2);
	if(iRet1 != 0)
	{
		printf("Error : Unable to create gun thread...\n");
		return -1;
	}
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}
