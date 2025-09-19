/*
===============================================================================
Name : 18a.c
Author : Guduru Veera Siva Somanath
Description : write lock on record
Date: 04-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define RECORD_SIZE 50

int main(int argc,char *argv[]){
	int fd,rec_no;
	struct flock lock;
	char buffer[RECORD_SIZE];

	if(argc != 2){
		write(2,"Usage: ./writer.out record_number\n",30);
		exit(1);
	}

	rec_no = atoi(argv[1]);

	fd = open("records.txt",O_RDWR | O_CREAT,0666);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = rec_no*RECORD_SIZE;
	lock.l_len = RECORD_SIZE;
	lock.l_pid = getpid();

	write(1,"Trying to acquire a write lock...\n",32);
	fcntl(fd,F_SETLKW,&lock);
	write(1,"Write lock acquired\n",21);
	lseek(fd,rec_no*RECORD_SIZE,SEEK_SET);
	snprintf(buffer, RECORD_SIZE, "Record Has Been Updated By Writter...");

	write(fd,buffer,strlen(buffer));

	write(1,"Press Enter to release lock...\n",32);
	getchar();

	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	write(1,"Lock released\n",15);

	close(fd);
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./wrtrec.out 2
	Trying to acquire a write lock..Write lock acquired
	Press Enter to release lock...

	Lock released
*/
