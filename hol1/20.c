/*
===============================================================================
Name : 20.c
Author : Guduru Veera Siva Somanath
Description :	Find out the priority of your running program. Modify the 
		priority with nice command.
Date: 01-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
	int pr = getpriority(PRIO_PROCESS,0);
	printf("Current Priority = %d\n",pr);

	nice(5);
	sleep(30);
	pr = getpriority(PRIO_PROCESS,0);
	printf("New Priority = %d\n",pr);

	return 0;
}
/*
Output 
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./20.out
	Current Priority = 0
	New Priority = 5
*/
