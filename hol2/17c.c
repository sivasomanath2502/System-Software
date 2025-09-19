/*
===============================================================================
Name : 17c.c
Author : Guduru Veera Siva Somanath
Description : Write a program to execute ls -l | wc use fcntl
Date: 15-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	int fd[2];

	if(pipe(fd) == -1)
	{
		perror("pipe");
		exit(1);
	}

	if(fork() == 0)
	{
		close(fd[0]);
		close(1);
		fcntl(fd[1],F_DUPFD,1);
		close(fd[1]);
		
		execlp("ls","ls","-l",NULL);
		exit(1);
	}
	else
	{
		close(fd[1]);
		close(0);
		fcntl(fd[0],F_DUPFD,0);
		close(fd[0]);

		execlp("wc","wc",NULL);
		perror("execlp wc");
		exit(1);
	}
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./17c.out
     	15     128     838
*/

