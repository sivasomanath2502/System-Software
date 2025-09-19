/*
===============================================================================
Name : 24.c
Author : Guduru Veera Siva Somanath
Description : Write a program to create an orphan process
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
		printf("Child: PID = %d Oiginal Parent PID = %d\n",getpid(),getppid());
		sleep(10);
		printf("Child: PID = %d New Parent PID = %d \n",getpid(),getppid());
	}
	else
	{
		printf("Parent: PID = %d exiting immediately\n",getpid());
		exit(0);
	}

	return 0;
}

/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./24.out
	Parent: PID = 5861 exiting immediately
	Child: PID = 5862 Oiginal Parent PID = 5861
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ Child: PID = 5862 New Parent PID = 1971 
*/
