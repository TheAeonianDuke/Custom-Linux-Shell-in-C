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
	// printf("I'm CAT command!\n");
	// for (int i=0; i<21; i++){
	// 	printf("%s\n", argv[i]);
	// }


	FILE *file;
	// char fileval[100];
	file=fopen(filedval[1],"r");

	if(file==NULL)
	{
		printf("Empty File!");
		exit(0);
	}
	
	else{
		char c=fgetc(file);
	int num=1;
	if (strcmp(filedval[2],"-n")==0)
	{
		printf("\n %d ", num);
		num++;
		while(c!=EOF)
		{	

			if(c!='\n')
			{
			printf("%c", c);
			c=fgetc(file);
			}

			else
			{
				printf("\n %d ", num);
				num++;
				c=fgetc(file);
			}
		}
	}

	else if(strcmp(filedval[2],"-E")==0)
	{
		while(c!=EOF)
		{	

			if(c!='\n')
			{
			printf("%c", c);
			c=fgetc(file);
			}

			else
			{
				printf(" $ \n");
				num++;
				c=fgetc(file);
			}
		}
	}

	else
	{
		printf("loll");
		file=fopen(filedval[1],"r");
		char c=fgetc(file);
		while(c!=EOF)
		{	
			printf("%c", c);
			c=fgetc(file);
			
		}
	}
}
	fclose(file);
	return 0;
}