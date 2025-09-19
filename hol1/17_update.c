/*
===============================================================================
Name : 17_update.c,17_init.c
Author : Guduru Veera Siva Somanath
Description :   Write a program to simulate online ticket reservation. Implement 		write lock Write a program to open a file, store a ticket 
		number and exit. Write a separate program, to open the file, 
		implement write lock, read the ticket number, increment the 
		number and print the new ticket number then close the file.
Date:04-Sep-2025
===============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	int fd;
	struct flock lock;
	int ticket;
	char buf[100];

	fd = open("ticket.txt",O_RDWR);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();

	write(1,"Trying to acquire write lock..\n",32);
	fcntl(fd,F_SETLKW,&lock);
	write(1,"Write lock acquired\n",21);

	lseek(fd,0,SEEK_SET);
	int n = read(fd,buf,sizeof(buf)-1);
	buf[n] = '\0';
	ticket = atoi(buf);

	ticket++;

	lseek(fd,0,SEEK_SET);
	dprintf(fd,"%d\n",ticket);

	char msg[100];
	int len = sprintf(msg,"Your ticket number is:%d\n",ticket);
	write(1,msg,len);
	write(1,"Ticket Number Updated press enter to exit\n",42);
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	write(1,"Lock Released.\n",15);

	close(fd);
	return 0;
}
/* 
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./17_update.out
	Trying to acquire write lock..
	Write lock acquired
	Your ticket number is:101
	Ticket Number Updated press enter to exit

	Lock Released.
*/
