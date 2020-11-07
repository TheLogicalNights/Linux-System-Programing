#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int iFd = 0;
	int iRet = 0;
	int iLen = 0;
	char cBuffer[1028] = {'\0'};
	if(argc!=1)
	{
		printf("Error : Invalid number of arguments\nUse <make help> for help");
		return -1;
	}
	else
	{
		iFd = open(argv[0],O_RDONLY);
		if(iFd==-1)
		{
			printf("Error : Unable to open file....\n");
			return -1;
		}
		else
		{
			iLen = sizeof(cBuffer);
			while((iRet = read(iFd,cBuffer,iLen))!=0)
			{
				cBuffer[iRet] = '\0';
				printf("%s",cBuffer);
			}	
		}
	}
	return 0;
}
