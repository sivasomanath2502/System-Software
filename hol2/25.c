/*
===============================================================================
Name : 25.c
Author : Guduru Veera Siva Somanath
Description : Write a program to print a message queue's metadata
Date: 16-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<time.h>

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
		perror("msgctl");
		exit(1);
	}
	printf("Access Permissions = %o\n", buf.msg_perm.mode);
   	printf("UID = %d, GID = %d\n", buf.msg_perm.uid, buf.msg_perm.gid);
   	printf("Last msg sent time = %s", ctime(&buf.msg_stime));
   	printf("Last msg received time = %s", ctime(&buf.msg_rtime));
   	printf("Last change time = %s", ctime(&buf.msg_ctime));
   	printf("Current number of bytes in queue = %lu\n", buf.__msg_cbytes);
   	printf("Number of messages in queue = %lu\n", buf.msg_qnum);
   	printf("Max number of bytes allowed = %lu\n", buf.msg_qbytes);
   	printf("PID of last msgsnd = %d\n", buf.msg_lspid);
    	printf("PID of last msgrcv = %d\n", buf.msg_lrpid);

    	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./25.out
	Access Permissions = 666
	UID = 1000, GID = 1000
	Last msg sent time = Thu Jan  1 05:30:00 1970
	Last msg received time = Thu Jan  1 05:30:00 1970
	Last change time = Fri Sep 19 07:56:09 2025
	Current number of bytes in queue = 0
	Number of messages in queue = 0
	Max number of bytes allowed = 16384
	PID of last msgsnd = 0
	PID of last msgrcv = 0
*/
