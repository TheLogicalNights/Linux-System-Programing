#include<stdio.h>                                          //Header file for IO operations
#include<fcntl.h>                                          //Header file for open function and O_RDONLY macro
#include<unistd.h>                                         //Header file for close function
#include<string.h>                                         //Header file for strcmp function
int main(
    int argc,                                              //Count of command line arguments
    char *argv[]                                           //Array of command line arguments
    )
{
    int iFd = 0;

    if(argc != 2)                                          //if there are no command line argument present 
    {
        printf("Error : Insufficient number of arguments...\n");
        printf("For help use <Executable_Name> -h\n");
        return -1;
    }
    if((strcmp(argv[1],"-h")==0) || ((strcmp(argv[1],"-H")==0)))
    {
        printf("Use : <Executable_Name> <File_Name>\n");
        return 0;
    }

    iFd  = open(argv[1]                                    //system call to open a file
                ,O_RDONLY                                  //Mode in which we want to open file here we are going to open file in read mode only
                );                                          

    if(iFd==-1)                                            //incase of some error open return -1
    {
        printf("Error : Unable to open file\n");
        return -1;
    }
    else                                                   //file opened successfully
    {
        printf("File opened successfully with file descripter : %d\n",iFd);
    }
    close(iFd);

    return 0;
}