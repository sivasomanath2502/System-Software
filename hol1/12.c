/*
===============================================================================
Name : 12.c
Author : Guduru Veera Siva Somanath
Description :Write a program to find out the opening mode of a file. Use fcntl.
Date: 25-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int fd,flags,access_mode;

	if(argc != 2)
	{
		fprintf(stderr,"Usage: %s filename\n",argv[0]);
		exit(1);
	}
	
	fd = open(argv[1], O_RDONLY | O_APPEND);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}

	flags = fcntl(fd,F_GETFL);
	if(flags<0)
	{
		perror("fcntl");
		close(fd);
		exit(1);
	}

	access_mode = flags & O_ACCMODE;
	if(access_mode == O_RDONLY)
		write(1,"File opened in: Read Only Mode\n",31);
	else if(access_mode == O_WRONLY)
		printf("File opened in: Write Only Mode\n");
	else if(access_mode == O_RDWR)
		printf("File opened in Read Write Mode\n");

	if(flags & O_APPEND)
		printf("O_APPEND flag is set\n");
	if(flags & O_NONBLOCK)
		printf("O_NONBLOCK flag is set\n");
	if(flags & O_SYNC)
		printf("O_SYNC flag is set\n");

	close(fd);
	return 0;
}

/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./12.out file1.txt
	File opened in: Read Only Mode
	O_APPEND flag is set
*/
