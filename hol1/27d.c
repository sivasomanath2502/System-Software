/*
===============================================================================
Name : 27d.c
Author : Guduru Veera Siva Somanath
Description : execv system call
Date: 04-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main()
{

	char *args[] = {"ls","-Rl",NULL};
        printf("Using execv:\n");
        execv("/bin/ls",args);
        perror("execv failed");
	
	return 1;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./27d.out
	Using execv:
	.:
	total 920
*/
