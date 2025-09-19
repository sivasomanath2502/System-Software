/*
===============================================================================
Name : 29.c
Author : Guduru Veera Siva Somanath
Description :   Write a program to get scheduling policy and modify the 
		scheduling policy
Date: 04-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sched.h>
#include<stdlib.h>
int main()
{
	pid_t pid = getpid();
	int policy;

	policy = sched_getscheduler(pid);
	printf("Current Scheduling policy:");

	switch(policy){
		case SCHED_OTHER: printf("SCHED_OTHER\n");break;
		case SCHED_FIFO:  printf("SCHED_FIFO\n");break;
		case SCHED_RR:    printf("SCHED_RR\n");break;
		}
	struct sched_param param;
	param.sched_priority = 50;
	if(sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
        	perror("sched_setscheduler");
        	exit(1);
   	 }
	printf("Scheduling policy changed to SCHED_FIFO with priority 50\n");

	policy = sched_getscheduler(pid);
	printf("New Scheduling policy:");
	switch(policy){
		case SCHED_OTHER: printf("SCHED_OTHER\n");break;
		case SCHED_FIFO:  printf("SCHED_FIFO\n");break;
		case SCHED_RR:    printf("SCHED_RR\n");break;
	}

	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ sudo ./29.out
	[sudo] password for gsomanath: 
	Current Scheduling policy:SCHED_OTHER
	Scheduling policy changed to SCHED_FIFO with priority 50
	New Scheduling policy:SCHED_FIFO
*/
