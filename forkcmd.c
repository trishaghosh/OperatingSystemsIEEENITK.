//fork - create a child process

/*fork()  creates  a  new process by duplicating the calling process.  The new process, referred to as the child, is an exact duplicate of the calling process, referred to as the parent process

On  success,  the  PID of the child process is returned in the parent, and 0 is returned in the child.  On failure, -1 is returned in the parent, no child process is created, and errno is set appropriately*/


#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
  pid_t pid = fork();
   
  if( pid == -1)
   {
     printf("Error: Child Process not created\n");
     exit(1);
   }
  else if( pid == 0)
   {
     printf("Hi! This is the CHILD PROCESS, with process id %d \nand PARENT PROCESS ID is %d \n", getpid(), getppid());
     _exit(0);
   }
  else
   {
     int parentid = getpid();
     printf("Parent Waiting till Child process has terminated\n");
     waitpid(pid, 0,0);
     printf("This is the parent Process with process id %d \n", parentid);
   }

exit(0);

}
