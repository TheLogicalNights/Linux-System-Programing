/*
	Problem Statement : Write a program which is used to demonstrate example of atomic read of file
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int iFd = 0;
	int iRet = 0;
	char data[1024] = {'\0'};
	
	if(argc!=2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	
	iFd = open(argv[1],O_RDONLY);
	
	if(iFd==-1)
	{
		printf("Error : Unable to open %s in read mode\n",argv[1]);
		return -1;
	}
	
	iRet = pread(iFd,data,sizeof(data),10);
	
	printf("%s",data);

	return 0;
}
