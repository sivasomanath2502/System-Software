/*
===============================================================================
Name : 18b.c
Author : Guduru Veera Siva Somanath
Description : read lock on record
Date: 04-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define RECORD_SIZE 50

int main(int argc,char *argv[])
{
	int fd,rec_no;
	struct flock lock;
	char buffer[RECORD_SIZE];

	if(argc != 2)
	{
		write(2,"Usage: ./reader.out record_number\n",30);
		exit(1);
	}

	rec_no = atoi(argv[1]);

	fd = open("records.txt",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}

	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = rec_no*RECORD_SIZE;
	lock.l_len = RECORD_SIZE;
	lock.l_pid = getpid();

	write(1,"Trying to acquire read lock...\n",32);
	fcntl(fd,F_SETLKW,&lock);
	write(1,"Read lock acquires!\n",21);

	lseek(fd,rec_no*RECORD_SIZE,SEEK_SET);
	read(fd,buffer,RECORD_SIZE);
	write(1,buffer,RECORD_SIZE);

	write(1,"\nPress Enter to release lock...\n",33);
	getchar();

	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	write(1,"Lock Released\n",15);

	close(fd);
	return 0;
}

/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./redrec.out 2
	Trying to acquire read lock...
	Read lock acquires!
	Record Has Been Updated By Writter...             
	Press Enter to release lock...

	Lock Released
*/
