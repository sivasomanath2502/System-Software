/*
===============================================================================
Name : 28.c
Author : Guduru Veera Siva Somanath
Description : Write a program to change the exiting message queue permission.
Date: 17-Sep-2025
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
	struct msqid_ds buf;

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
	if(msgctl(msqid,IPC_STAT,&buf) == -1)
	{
		perror("msgctl IPC_STAT");
		exit(1);
	}
	buf.msg_perm.mode = 0664;
	if(msgctl(msqid,IPC_SET,&buf) == -1)
	{
		perror("msgctl IPC_SET");
		exit(1);
	}
	if(msgctl(msqid,IPC_STAT,&buf) == -1)
	{
		perror("msgctl IPC_STAT(verify)");
		exit(1);
	}

	printf("New Permissions = %o\n",buf.msg_perm.mode);

	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./28.out
	New Permissions = 664
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ipcs -q

	------ Message Queues --------
	key        msqid      owner      perms      used-bytes   messages    
	0x41075160 1          gsomanath  664        0            0        
*/
