/*
===============================================================================
Name : 27c.c
Author : Guduru Veera Siva Somanath
Description : execle system call
Date: 04-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Using execle:\n");
        char *env[] = {NULL};
        execle("/bin/ls","ls","-Rl",(char *)NULL,env);
        perror("execle failed");

	return 1;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./27c.out
	Using execle:
	.:
	total 920
*/
