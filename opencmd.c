//Open is a system call that is used to open a new file and obtain its file descriptor.
/* int open(const char *path, int oflags);
   int open(const char *path, int oflags, mode_t mode);
  
   const char*path - The relative or absolute path to the file that is to be opened.
   int oflags - A bitwise 'or' separated list of values that determine the method in which the file is to be opened (whether it should be read only, read/write, whether it should be cleared when opened, etc).
   mode_t mode - A bitwise 'or' separated list of values that determine the permissions of the file if it is created
   return value - Returns the file descriptor for the new file. The file descriptor returned is always the smallest integer greater than zero that is still available. If a negative value is returned, then there was an error opening the file.
  
   O_RDONLY	Open the file so that it is read only.
   O_WRONLY	Open the file so that it is write only.
   O_RDWR	Open the file so that it can be read from and written to.
   O_APPEND	Append new information to the end of the file.
   O_TRUNC	Initially clear all data from the file.
   O_CREAT	If the file does not exist, create it. If the O_CREAT option is used, then you must include the third parameter.
   O_EXCL	Combined with the O_CREAT option, it ensures that the caller must create the file. If the file already exists, the call will fail.   

  S_IRUSR	Set read rights for the owner to true.
  S_IWUSR	Set write rights for the owner to true. 
  S_IXUSR	Set execution rights for the owner to true.
  S_IRGRP	Set read rights for the group to true.
  S_IWGRP	Set write rights for the group to true.
  S_IXGRP	Set execution rights for the group to true.
  S_IROTH	Set read rights for other users to true.
  S_IWOTH	Set write rights for other users to true.
  S_IXOTH	Set execution rights for other users to true. */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

void main()
{
  int file1 = open("testfile.txt", O_APPEND | O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
  char inpt[200];

  if(file1 < 0)
   {
     printf("ERROR: Failed to open File \n");
     exit(0);
   }

  printf("Enter what you would like to write to the file\n");
  gets(inpt);
  write(file1, inpt, strlen(inpt));

  close(file1);

 }
