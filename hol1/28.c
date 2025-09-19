/*
===============================================================================
Name : 28.c
Author : Guduru Veera Siva Somanath
Description :Write a program to get maximum and minimum real time priority.
Date: 04-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<sched.h>

int main()
{
	int max_priority,min_priority;

	max_priority = sched_get_priority_max(SCHED_FIFO);
	min_priority = sched_get_priority_min(SCHED_FIFO);
	
	printf("SCHED_FIFO -> Max Priroity: %d, Min Priority: %d\n",max_priority,min_priority);

	max_priority = sched_get_priority_max(SCHED_RR);
        min_priority = sched_get_priority_min(SCHED_RR);
        
        printf("SCHED_RR -> Max Priroity: %d, Min Priority: %d\n",max_priority,min_priority);
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./28.out
	SCHED_FIFO -> Max Priroity: 99, Min Priority: 1
	SCHED_RR -> Max Priroity: 99, Min Priority: 1
*/
