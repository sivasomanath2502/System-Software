/*
===============================================================================
Name : 19.c
Author : Guduru Veera Siva Somanath
Description :   Write a program to find out time taken to execute getpid system 
		call. Use time stamp counter.
Date: 01-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdint.h>

static __inline__ unsigned long long rdtsc(void)
{
	unsigned hi,lo;
	__asm__ volatile("rdtsc":"=a"(lo),"=d"(hi));

	return ((unsigned long long)lo) | (((unsigned long long)hi) << 32);
}

int main()
{
	unsigned long long start,end;
	pid_t pid;

	start = rdtsc();
	pid = getpid();
	end = rdtsc();

	printf("PID = %d\n",pid);
	printf("Cycles taken = %llu\n",end-start);

	return 0;
}

/*  
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./19.out
	PID = 5669
	Cycles taken = 18114
*/
