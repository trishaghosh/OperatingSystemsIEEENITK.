// execl, execlp, execle, execv, execvp, execvpe - execute a file

/* The  exec()  family  of functions replaces the current process image with a new process image. execve() does not return on success, and the text, data, bss, and stack of the calling process are overwritten by that of the program loaded.

exec is a functionality of an operating system that runs an executable file in the context of an already existing process, replacing the previous executable. This act is also referred to as an overlay. It is especially important in Unix-like systems, although exists elsewhere. As a new process is not created, the process identifier (PID) does not change, but the machine code, data, heap, and stack of the process are replaced by those of the new program.*/

//With Unix V6 the argument list of an exec() call was ended by 0, while the argument list of main was ended by -1. Thus, this argument list was not directly usable in a further exec() call. Since Unix V7 both are NULL.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
  char *prgname[] = {NULL,"forkcmd.exe",NULL};
  char *environ[] = {NULL};

   execve(prgname[1], prgname, environ);
   perror("execve failed");   /* execve() only returns on error */
   exit(0);
}

