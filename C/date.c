#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc,char *filedval[])
{
	char cmdbuf[21];
	if(filedval[1]!=NULL){
	snprintf(cmdbuf, sizeof(cmdbuf), "date %s", filedval[1]);
	system(cmdbuf);

}

	else{
		system("date");
	}
}