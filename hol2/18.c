/*
===============================================================================
Name : 18.c
Author : Guduru Veera Siva Somanath
Description :   Write a program to find out total number of directories on the 
		pwd.execute ls -l | grep ^d | wc ? Use only dup2.
Date: 15-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	int fd1[2],fd2[2];

	if(pipe(fd1) == -1 || pipe(fd2) == -1)
	{
		perror("pipe");
		exit(1);
	}

	if(fork() == 0)
	{
		dup2(fd1[1],STDOUT_FILENO);
		close(fd1[0]);close(fd1[1]);
		close(fd2[0]);close(fd2[1]);

		execlp("ls","ls","-l",NULL);
		perror("execlp ls");
		exit(1);
	}
	if(fork() == 0)
	{
		dup2(fd1[0],STDIN_FILENO);
		dup2(fd2[1],STDOUT_FILENO);

		close(fd1[0]);close(fd1[1]);
		close(fd2[0]);close(fd2[1]);

		execlp("grep","grep","^d",NULL);
		perror("execlp grep");
		exit(1);
	}
	else
	{
		dup2(fd2[0],STDIN_FILENO);

		close(fd1[0]);close(fd1[1]);
		close(fd2[0]);close(fd2[1]);

		execlp("wc","wc",NULL);
		perror("execlp wc");
		exit(1);
	}
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./18.out
	2      18     116
*/

