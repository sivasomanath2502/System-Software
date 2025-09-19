/*
===============================================================================
Name : 19e.c
Author : Guduru Veera Siva Somanath
Description : Create a FIFO file by mkfifo library function
Date: 15-Sep-2025
===============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	if(mkfifo("fifo_lib",0666) == -1)
	{
		perror("mkfifo");
		exit(1);
	}
	printf("FIFO created suing mkfifo library function\n");
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./19e.out
	FIFO created suing mkfifo library function
*/
