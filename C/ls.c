#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc,char *filedval[])
{
	printf("I'm LS command!\n");

	DIR *dir;
	struct dirent *reader;
	dir=opendir(".");
	// printf(filedval[1]);
	if(dir==NULL)
	{
		printf("Empty Directory!");
		exit(0);
	}
	
	if (strcmp(filedval[1],"-i")==0)
	{
		while((reader=readdir(dir))!=NULL)
		{
			printf("%ld %s\n", (*reader).d_ino,(*reader).d_name);
		}
	}

	else if (strcmp(filedval[1],"-a")==0)
	{
		while((reader=readdir(dir))!=NULL)
		{
			printf("%s\n", (*reader).d_name);
		}
	}

	else{
		while((reader=readdir(dir))!=NULL)
	{
		printf("%s\n", (*reader).d_name);
	}
	}



	closedir(dir);
	return 0;
}