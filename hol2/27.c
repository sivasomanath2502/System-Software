/*
===============================================================================
Name : 27.c
Author : Guduru Veera Siva Somanath
Description : Write a program to receive messages from the message queue.
		a. with 0 as a flag
		b. with IPC_NOWAIT as a flag
Date: 17-Sep-2025
===============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>

struct msg_buffer{
	long msg_type;
	char msg_text[100];
};

int main()
{
	key_t key;
	int msqid;
	struct msg_buffer msg;

	key = ftok("msgfile",65);
	msqid = msgget(key,0666 | IPC_CREAT);

	msgrcv(msqid,&msg,sizeof(msg.msg_text),1,0);
	printf("Blocking receive: %s\n",msg.msg_text);

	if(msgrcv(msqid,&msg,sizeof(msg.msg_text),1,IPC_NOWAIT) == -1)
	{
		if(errno == ENOMSG)
		{
			printf("Non-blocking receive: No message available\n");
		}
		else
		{
			perror("msgrcv");
		}
	}
	else
	{
		printf("Non-blocking receive:%s\n",msg.msg_text);
	}
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./27.out
	Blocking receive: Hii First Message

	Non-blocking receive:Second Message
*/
