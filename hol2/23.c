/*
===============================================================================
Name : 23.c
Author : Guduru Veera Siva Somanath
Description :   Write a program to print the maximum number of files can be 
		opened within a process and size of a pipe (circular buffer).
Date: 16-Sep-2025
===============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main()
{
	long PIPE_BUF,OPEN_MAX;
	PIPE_BUF = pathconf(".",_PC_PIPE_BUF);
	OPEN_MAX = sysconf(_SC_OPEN_MAX);
	printf("Pipe_buf=%ld\t Open_Max = %ld\n",PIPE_BUF,OPEN_MAX);
	return 0;
}
/*
Output
	somanath@gsomanath-Inspiron-15-5518:~/hol2$ ./23.out
	Pipe_buf=4096	 Open_Max = 1024
*/
