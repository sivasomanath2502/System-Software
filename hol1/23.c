/*
===============================================================================
Name : 23.c
Author : Guduru Veera Siva Somanath
Description : Write a program to create a Zombie state of the running program.
Date: 01-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	if(fork() == 0)
	{
		printf("Child: PID = %d exiting...\n",getpid());
		exit(0);
	}
	else
	{
		printf("Parent: PID = %d\n",getpid());
		sleep(30);
		printf("Parent exiting, zombie (child) will be reaped automatically now.\n");
	}
	return 0;
}

/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./23.out &
	[2] 5829
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ Parent: PID = 5829
	Child: PID = 5830 exiting...
	Parent exiting, zombie (child) will be reaped automatically now.
	[2]+  Done                    ./23.out
*/
