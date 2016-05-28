//system - execute a shell command

/*The  system()  library  function uses fork(2) to create a child process
       that executes the shell command specified in command using execl(3)  as
       follows:

           execl("/bin/sh", "sh", "-c", command, (char *) 0);

       system() returns after the command has been completed.

 If command is NULL, then system() returns a status indicating whether a
       shell is available on the system

RETURN VALUE
       The return value of system() is one of the following:

       *  If command is NULL, then a nonzero value if a shell is available, or
          0 if no shell is available.

       *  If a child process could not be created, or its status could not  be
          retrieved, the return value is -1.

       *  If  a  shell  could  not  be executed in the child process, then the
          return value is as though the  child  shell  terminated  by  calling
          _exit(2) with the status 127.

       *  If  all  system calls succeed, then the return value is the termina‐
          tion status of the child shell used to execute command.  (The termi‐
          nation  status of a shell is the termination status of the last com‐
          mand it executes.)

       In the last two cases, the return value is a "wait status" that can  be
       examined  using the macros described in waitpid(2).  (i.e., WIFEXITED()
       WEXITSTATUS() and so on).

       system() does not affect the wait status of any other children. */

#include<stdio.h>
#include<stdlib.h>


void main()
{
   int status;
   char cmd[100];
   
   printf("Enter any Unix Shell Command\n");
   gets(cmd);
   
   status = system(cmd);
 
   if( status < 0)
   {
     printf("ERROR: Child Process could not be created\n");
     exit(0);
   }
 
  printf("Termination value of the Child Process : %d \n",status);
 
}


