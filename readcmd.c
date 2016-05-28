// read - read from a file descriptor

/*read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.

       On  files  that  support seeking, the read operation commences at the current file offset, and the file offset is incremented by the number of bytes read.  If the current file offset is at or
       past the end of file, no bytes are read, and read() returns zero.

       If count is zero, read() may detect the errors described below.  In the absence of any errors, or if read() does not check for errors, a read() with a count of 0 returns zero and has no other
       effects.

       If count is greater than SSIZE_MAX, the result is unspecified.

 On  success, the number of bytes read is returned (zero indicates end of file), and the file position is advanced by this number.  It is not an error if this number is smaller than the number
       of bytes requested; this may happen for example because fewer bytes are actually available right now (maybe because we were close to end-of-file, or because we are reading  from  a  pipe,  or
       from a terminal), or because read() was interrupted by a signal.  On error, -1 is returned, and errno is set appropriately.  In this case, it is left unspecified whether the file position (if
       any) changes.
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

void main()
{
  int file1 = open("testfile.txt", O_APPEND | O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
  char inpt[200];
  int n;
  int stat;

  if(file1 < 0)
   {
     printf("ERROR: Failed to open File \n");
     exit(0);
   }

  printf("Enter what you would like to write to the file\n");
  gets(inpt);
  write(file1, inpt, strlen(inpt));
  
  stat = system("cat testfile.txt");

  if(stat<0)
   {
     printf("ERROR:Could Not create child process\n");
     exit(0);
   }

  printf("\nThese are the current contents of the file\n");

  printf("Enter the number of bytes you want to read from the file\n");
  scanf("%d",&n);
 
  int status = read(file1, inpt,n);

  printf("Return Status of read command = %d \n", status);
  perror("Read Error");

  close(file1);

}
  
