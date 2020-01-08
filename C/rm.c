#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


int main(int argc,char *filedval[])
{
	// printf(fileval[1]);
	printf("I'm RM command!\n");
	// for (int i=0; i<21; i++){
	// 	printf("%s\n", argv[i]);
	// }
	if(strcmp(filedval[1],"-I")==0)
	{
		printf("Do You Want to Delete %s\n",filedval[2]);
		char choice[5];
		scanf("%c",&choice);
		remove(filedval[2]);
		
		
	}
	else
		{
			printf("Not Deleted");
		}

	
	return 0;
}	