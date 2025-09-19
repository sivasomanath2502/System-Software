/*
===============================================================================
Name : 28e.c
Author : Guduru Veera Siva Somanath
Description : execvp system call
Date: 04-Sep-2025
===============================================================================
*/


#include<stdio.h>
#include<unistd.h>

int main()
{
	char *args[] = {"ls","-Rl",NULL};
	printf("Using execvp:\n");
        execvp("ls",args);
        perror("execvp failed");

	return 1;
}

/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./27e.out
	Using execvp:
	.:
	total 920
*/
