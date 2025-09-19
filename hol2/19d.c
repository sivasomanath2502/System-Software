/*
===============================================================================
Name : 19d.c
Author : Guduru Veera Siva Somanath
Description : Create a FIFO file by mknod system call
Date: 15-Sep-2025
===============================================================================
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	if(mknod("fifo_sys",S_IFIFO | 0666,0) == -1)
	{
		perror("mknod");
		exit(1);
	}
	printf("FIFO created using mknod system call\n");
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./19d.out
	FIFO created using mknod system call
*/	
