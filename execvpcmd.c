//execl, execlp, execle, execv, execvp, execvpe - execute a file
/* The execv(), execvp(), and execvpe() functions provide an array of pointers to null-terminated strings that represent the argument list available to the new program.  The first  argument,  by
       convention, should point to the filename associated with the file being executed.  The array of pointers must be terminated by a null pointer.*/
// The exec() functions return only if an error has occurred.  The return value is -1, and errno is set to indicate the error.

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

/*void main()
{
  char *prgname[] = {"execcmd.exe",NULL};
  char *environ[] = {NULL};

   execvp(prgname[0], prgname);
   perror("execvp failed");   //execvp() only returns on error 
   exit(0);
}*/
void main() {
    char *name[6];

    name[0] = "/bin/bash";
    name[1] = "-c";
    name[2] = "ls -l";
    name[3] = "cd ..";
    name[4] = "ls";
    name[5] = NULL;

  execvp(name[0], name);
  perror("execvp Failed"); //execvp() only returns on error 
  exit(0);
 
}

