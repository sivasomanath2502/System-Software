/*
===============================================================================
Name : 25.c
Author : Guduru Veera Siva Somanath
Description : 	Write a program to create three child processes. The parent 
		should wait for a particular child
Date: 01-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	pid_t pid1,pid2,pid3;
	int choice;

	pid1 = fork();
	if(pid1 == 0)
	{
		printf("Child1: PID = %d\n",getpid());
		sleep(2);
		exit(10);
	}
	pid2 = fork();
        if(pid2 == 0)
        {
                printf("Child2: PID = %d\n",getpid());
                sleep(2);
                exit(20);
        }
	pid3 = fork();
        if(pid3 == 0)
        {
                printf("Child3: PID = %d\n",getpid());
                sleep(2);
                exit(30);
        }
	fflush(stdout);
	printf("Enter child number to wait for:"); 
	scanf("%d",&choice);

	pid_t wait_pid;
	switch(choice)
	{
		case 1: wait_pid = pid1;break;
		case 2: wait_pid = pid2;break;
		case 3: wait_pid = pid3;break;
	}

	int status;
	pid_t finished = waitpid(wait_pid,&status,0);
	printf("Parent: Child %d finished with exit status = %d\n",choice,WEXITSTATUS(status));
	    if(wait_pid != pid1) waitpid(pid1, NULL, 0);
	    if(wait_pid != pid2) waitpid(pid2, NULL, 0);
   	    if(wait_pid != pid3) waitpid(pid3, NULL, 0);
	    printf("Parent: All children finished. Exiting.\n");
    return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./25.out
	Child1: PID = 6047
	Child2: PID = 6048
	Enter child number to wait for:Child3: PID = 6049
	2
	Parent: Child 2 finished with exit status = 20
	Parent: All children finished. Exiting.
*/
