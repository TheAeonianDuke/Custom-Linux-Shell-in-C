#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
// char* input(void)
// {
// 	char* inputval;
// 	printf("Hello! Welcome to Abhi's xterminalx, the most powerful terminal! \n");
// 	printf("I'm the child process with pid %d and I will be your terminal. Input a command. \n", getpid());
// 	printf("-> ");
// 	scanf("%s", inputval);
// 	printf(inputval);
// 	return (inputval);
// }

void cd_command(char* inputvalue)
{
	
	system(inputvalue);
	system("pwd");
	
}

int main()
{
	// clear();
	system("clear");
	pid_t child=fork();
	if(child<0)
	{
		perror("Fork Error. PID<0.");
		exit(-1);

	}

	if (child!=0)
	{
		// printf("I'm the parent with pid %d\n", getpid() );
		wait(NULL);

	}

	if (child==0)
	{

		int exitfn=0;	
		int counterval=0;	
		char history[100][21];
		printf("Hello! Welcome to Abhi's xterminalx, the most powerful terminal! \n");
		printf("I'm the child process with pid %d and I will be your terminal. Input a command. \n", getpid());
		
		while (exitfn<=0)
		{
			char inputval[21] ={0x0};
			char *ptr =inputval;
			char *args[21]={NULL};
			printf("\n -> ");
			fgets(inputval,21,stdin);
			// printf("%s\n",  );
			strcpy(history[counterval],inputval);
			counterval+=1;
			for (int i=0; i<sizeof(args) && *ptr; ptr++)
			{
				if (*ptr ==' ') continue;
				if (*ptr == '\n') break;
				for (args[i++] = ptr; *ptr && *ptr != ' ' && *ptr != '\n'; ptr++);
	        		*ptr = '\0';
			}


			// scanf("%s", inputval);
			// printf(inputval);
			
			if (strcmp(inputval, "ls")==0)
			{
				pid_t newchild=fork();
				if (newchild == 0)
				{
					execv("ls",args);
					// exit(0);
				} 
				wait(NULL);

				// printf("input is %d", *inputval);
			}	

			if (strcmp(inputval, "cat")==0)
			{
				pid_t newchild=fork();
				if (newchild == 0){

					// printf(args[1]);
					execv("cat",args);
					// system("pwd");
					// exit(0);
				} 
				wait(NULL);

				// printf("input is %d", *inputval);
			}

			if (strcmp(inputval, "date")==0)
			{
				pid_t newchild=fork();
				if (newchild == 0)
				{
					
					execv("date",args);
					// exit(0);
				} 
				wait(NULL);

				// printf("input is %d", *inputval);
			}	

			if (strcmp(inputval, "rm")==0)
			{
				pid_t newchild=fork();
				if (newchild == 0)
				{
					execv("rm",args);
					// exit(0);
				} 
				wait(NULL);

				// printf("input is %d", *inputval);
			}	

			if (strcmp(inputval, "mkdir")==0)
			{
				pid_t newchild=fork();
				if (newchild == 0)
				{
					execv("mkdir",args);
					// exit(0);
				} 
				wait(NULL);

				// printf("input is %d", *inputval);
			}	


			if (strcmp(inputval, "cd")==0)
			{
				pid_t newchild=fork();
				if (newchild == 0){
					chdir(args[1]);
					system("pwd");
					// exit(0);
				} 
				wait(NULL);

				// printf("input is %d", *inputval);
			}

			if (strcmp(inputval, "pwd")==0)
			{
				pid_t newchild=fork();
				if (newchild == 0){
					
					system("pwd");
					// exit(0);
				} 
				wait(NULL);

				// printf("input is %d", *inputval);
			}	
	

			if (strcmp(inputval, "echo")==0)
			{
				if (fork() == 0)
				{
					execvp(args[0], args);
					// exit(0);
				} 
				wait(NULL);

				// printf("input is %d", *inputval);
			}	


			if (strcmp(inputval, "history")==0)
			{
				// if (fork() == 0)
				// {
				// 	execvp(args[0], args);
				// 	exit(0);
				// } 
				// wait(NULL);
				int loop;
				for (loop =0; loop< counterval; loop++){
					printf("%s", history[loop]);
					// printf("\n");
				}

				// printf("input is %d", *inputval);
			}	

			if (strcmp(inputval, "exit")==0)
			{
				
				// break;
				exit(0);
			}	

		}


		
		// sleep(5);

	}
return 0;
}

