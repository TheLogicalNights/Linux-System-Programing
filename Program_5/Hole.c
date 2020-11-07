/*
	Problem Statement : Write a program which is used to create a hole of 1kb in the file.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int iFd = 0;
	
	if(argc!=2)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	
	iFd = open(argv[1],O_WRONLY);
	
	if(iFd==-1)
	{
		printf("Error : Unable to open %s in write mode\n",argv[1]);
		return -1;
	}
	else
	{
		lseek(iFd,1024,SEEK_END);
		write(iFd," ",1);
	}
	return 0;
}
