/*
===============================================================================
Name : 14.c
Author : Guduru Veera Siva Somanath
Description :   Write a simple program to create a pipe, write to the pipe, read 		from pipe and display on the monitor.
Date: 14-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int fd[2];
	char write_msg[] = "Hello, This is the demo for Pipe Read/Write";
	char read_msg[100];

	if(pipe(fd) == -1)
	{
		perror("pipe");
		exit(0);
	}

	write(fd[1],write_msg,strlen(write_msg));

	read(fd[0],read_msg,sizeof(read_msg));

	printf("The message recevied from pipe:%s\n",read_msg);
	
	close(fd[0]);
	close(fd[1]);
	return 0;
}

/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./14.out
	The message recevied from pipe:Hello, This is the demo for Pipe Read/Write
*/
