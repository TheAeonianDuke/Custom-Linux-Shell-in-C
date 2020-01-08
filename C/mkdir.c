#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdint.h>
#include <inttypes.h>

int main(int argc,char *filedval[])
{
	// printf(fileval[1]);
	printf("I'm MKDIR command!\n");
	// for (int i=0; i<21; i++){
	// 	printf("%s\n", argv[i]);
	// }


	// mkdir(filedval[1],555);
	
	if(filedval[1]!=NULL)
	{
		if(strcmp(filedval[2],"-m")==0)
			
		{
			
			// long temp = atol(filedval[3]);
			// unsigned int out = (unsigned int)temp;
			// unsigned int offset = (uintptr_t)filedval[3];

			unsigned int out = strtoul(filedval[3],NULL,10);
			printf("%x\n",out);
			mkdir(filedval[1],out);
		}

		if(strcmp(filedval[2],"-v")==0)
		{
			mkdir(filedval[1],555);
			printf("Directory created with name %s!\n",  filedval[1]);
		}
	}

	if(filedval[2]==NULL)
	{
		mkdir(filedval[1],555);
	}
	return 0;
}
