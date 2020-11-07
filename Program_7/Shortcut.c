/*
	Problem Statement : write a program which is used create symbolic link.
*/

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc,char *argv[])
{
	int iFd = 0;
	int iRet = 0;
	char data[1024] = {'\0'};
	if(argc!=3)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	
	iFd = symlink(argv[1],argv[2]);
	
	if(iFd==-1)
	{
		printf("Error : Unable to create shortcut\n");
		return -1;
	}
	else
	{
		printf("Shortcut created successfully\n");
	}
	
	return 0;
}
