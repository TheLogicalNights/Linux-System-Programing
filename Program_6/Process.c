/*
	Problem Statement : Write a program which create one child process and child process reads the contents of a another file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
	int iRet = 0;
	int pid = 0;
	int status = 0;
	char path[1024] = {'\0'};
	if(argc!=2)
	{
		printf("Error : Inavalid number of arguments\nUse <make help> for help\n");
		return -1;
	}
	else
	{
		if((iRet=fork())==0)
		{
			execl("./File",argv[1],NULL);
		}
		else
		{
			pid = wait(&status);
		}
	}
	return 0;
}
