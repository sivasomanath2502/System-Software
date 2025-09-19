/*
===============================================================================
Name : 24.c
Author : Guduru Veera Siva Somanath
Description :	Write a program to create a message queue and print the key 
		and message queue id.
Date: 16-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main()
{
	key_t key;
	int msqid;

	key = ftok("msgfile",65);
	if(key == -1)
	{
		perror("ftok");
		exit(1);
	}
	msqid = msgget(key,0666 | IPC_CREAT);
	if(msqid == -1){
		perror("msgget");
		exit(1);
	}
	printf("Key = %d\n",key);
	printf("Message Queue ID = %d\n",msqid);


	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./24.out
	Key = 1090998624
	Message Queue ID = 0
*/
