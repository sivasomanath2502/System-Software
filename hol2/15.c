/*
===============================================================================
Name : 15.c
Author : Guduru Veera Siva Somanath
Description :   Write a simple program to send some data from parent to the 
		child process
Date: 13-09-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
int main()
{
	int fd[2];
	char write_msg[] = "Hello from parent to child via Pipe";
	char read_msg[100];

	if(pipe(fd) == -1)
	{
		perror("pipe failed");
		exit(1);
	}

	if(fork() == 0)
	{
		close(fd[1]);
		read(fd[0], read_msg, sizeof(read_msg));
		printf("Child Received:%s\n",read_msg);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		write(fd[1],write_msg,strlen(write_msg)+1);
		close(fd[1]);
		wait(NULL);
	}
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./15.out
	Child Received:Hello from parent to child via Pipe
*/
