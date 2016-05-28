// vfork - create a child process and block parent

/* vfork() is a special case of clone(2).  It is used to create new processes without copying the page tables of the parent process.  It may be useful in performance-sensitive applications where
       a child is created which then immediately issues an execve(2). 
 (From  POSIX.1)  The vfork() function has the same effect as fork(2), except that the behavior is undefined if the process created by vfork() either modifies any data other than a variable of
       type pid_t used to store the return value from vfork(), or returns from the function in which vfork() was called, or calls any other function before successfully calling _exit(2)  or  one  of
       the exec(3) family of functions.*/


#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
  pid_t pid = vfork();
   
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

