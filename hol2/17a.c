/*
===============================================================================
Name : 17a.c
Author : Guduru Veera Siva Somanath
Description :	Write a program to execute ls -l | wc use dup
Date: 15-Sep-2025
===============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

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
		dup(fd[1]);
		close(fd[1]);

		execlp("ls","ls","-l",NULL);
		perror("execlp ls");
		exit(1);
	}
	else
	{
		close(fd[1]);
		close(0);
		dup(fd[0]);
		close(fd[0]);

		execlp("wc","wc",NULL);
		perror("execlp wc");
		exit(1);
	}
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./17a.out
        11      92     601
*/
