/*
===============================================================================
Name : 27a.c
Author : Guduru Veera Siva Somanath
Description : 	Write a program to execute ls -Rl by the following system calls
		a. execl
Date: 04-Sep-2025
===============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	char *args[] = {"ls","-Rl",NULL};

	printf("Using execl:\n");
	execl("/bin/ls","ls","-Rl",(char *)NULL);
	perror("execl failed");
	
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./27a.out
	Using execl:
	.:
	total 920
*/
