#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_LINE 80 //Maximum length of command

int main(void)
{
 //command line argument
 char *args[MAX_LINE/2 +1];
 // flag to determine when to exit program
 int should_run = 1;
 int i = 0;
 
 
 while(should_run)
 {
	printf ("osh>\n");
  fflush(stdout);
  
  args[i] = (char*)malloc(100);
  scanf("%s", args[i]);
  args[i+1] = NULL;
  
  
	printf("Fork created\n");
	//declare pid and fork the child process
 	pid_t pid = fork();

	printf("pid is %d\n", pid);
 	
 	//check if error occured
 	if (pid < 0){
 		fprintf(stderr, "Fork Failed");
 		return 1;
 	}	
 	else if (pid == 0){
 	//child process
 	  printf("Child execute \n");
 		execvp(args[i], args); 
   	printf("Unknown command\n");
   	return 0;
 	}
 	else{
 	//parent process
 		wait(NULL);
 		printf("Child Complete \n");
 		i++;
  //	should_run = 0;
 	}
 }



return 0;
}

