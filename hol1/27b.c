/*
===============================================================================
Name : 27b.c
Author : Guduru Veera Siva Somanath
Description : execlp system call
Date: 04-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Using execlp:\n");
        execlp("ls","ls","-Rl",(char *)NULL);
        perror("excelp failed");	

	return 1;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./27b.out
	Using execlp:
	.:
	total 920
*/
