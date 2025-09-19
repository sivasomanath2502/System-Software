/*
===============================================================================
Name : 29.c
Author : Guduru Veera Siva Somanath
Description : Write a program to remove the message queue.
Date: 17-Sep-2025
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msqid;

    key = ftok("msgfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl IPC_RMID");
        exit(1);
    }

    printf("Message queue (msqid=%d) removed successfully.\n", msqid);

    return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./29.out
	Message queue (msqid=1) removed successfully.
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ipcs -q

	------ Message Queues --------
	key        msqid      owner      perms      used-bytes   messages   
*/
