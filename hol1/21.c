/*
===============================================================================
Name : 21.c
Author : Guduru Veera Siva Somanath
Description : Write a program, call fork and print the parent and child process id.
Date: 01-Sep-2025
===============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	if(fork() == 0)
	{
		printf("Child process: PID = %d,Parent PID = %d\n",getpid(),getppid());
	}
	else
	{
		printf("Parent process: PID = %d\n",getpid());
	}
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./21.out
	Parent process: PID = 5757
	Child process: PID = 5758,Parent PID = 5757
*/
