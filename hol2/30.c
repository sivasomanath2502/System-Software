/*
===============================================================================
Name : 30.c
Author : Guduru Veera Siva Somanath
Description : Write a program to create a shared memory.
		a. write some data to the shared memory
		b. attach with O_RDONLY and check whether you are able to overwrite.
		c. detach the shared memory
		d. remove the shared memory
Date: 17-Sep-2025
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024  

int main() {
    key_t key;
    int shmid;
    char *data;

    // 1. Create shared memory
    key = ftok("shmfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    printf("Shared memory created (shmid=%d)\n", shmid);

    // 2. Attach with read/write and write some data
    data = (char*) shmat(shmid, NULL, 0);
    if (data == (char*) -1) {
        perror("shmat");
        exit(1);
    }
    strcpy(data, "Hello, this is shared memory demo!");
    printf("Written to shared memory: %s\n", data);

    // 3. Attach with O_RDONLY and try to overwrite
    char *ro_data = (char*) shmat(shmid, NULL, SHM_RDONLY);
    if (ro_data == (char*) -1) {
        perror("shmat read-only");
    } else {
        printf("Read-only attach successful. Current content: %s\n", ro_data);
        printf("Trying to overwrite in read-only segment...\n");
        shmdt(ro_data);
    }

    // 4. Detach the first attachment
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }
    printf("Shared memory detached.\n");

    // 5. Remove the shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    printf("Shared memory removed.\n");

    return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./30.out
	Shared memory created (shmid=0)
	Written to shared memory: Hello, this is shared memory demo!
	Read-only attach successful. Current content: Hello, this is shared memory demo!
	Trying to overwrite in read-only segment...
	Shared memory detached.
	Shared memory removed.
*/
