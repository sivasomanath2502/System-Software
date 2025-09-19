/*
===============================================================================
Name : 26.c
Author : Guduru Veera Siva Somanath
Description :   Write a program to send messages to the message queue. 
		Check $ipcs -q
Date: 16-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

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
	if(key == -1)
	{
		perror("ftok");
		exit(1);
	}
	msqid = msgget(key,0666 | IPC_CREAT);
	if(msqid == -1)
	{
		perror("msgget");
		exit(1);
	}
	msg.msg_type = 1;
	printf("Enter message to send:");
	fgets(msg.msg_text,sizeof(msg.msg_text),stdin);

	if(msgsnd(msqid,&msg,sizeof(msg.msg_text),0) == -1)
	{
		perror("msgsnd");
		exit(1);
	}

	printf("Message sent to queue(msqid=%d)\n",msqid);

	return 0;
}
/*
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./26.out
	Enter message to send:Hello From Siva
	Message sent to queue(msqid=1)
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ipcs -q

	------ Message Queues --------
	key        msqid      owner      perms      used-bytes   messages
	0x41075160 1          gsomanath  666        100          1
*/
