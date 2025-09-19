/*
===============================================================================
Name : 22.c
Author : Guduru Veera Siva Somanath
Description :  Write a program to wait for data to be written into FIFO 
		within 10 seconds, use select system call with FIFO.
Date: 16-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main()
{
	char buffer[100];
	int fd;
	fd_set readfds;
	struct timeval timeout;

	fd = open("myfifo",O_RDONLY | O_NONBLOCK);
	if(fd == -1)
	{
		perror("open fifo");
		exit(1);
	}
	FD_ZERO(&readfds);
	FD_SET(fd,&readfds);

	timeout.tv_sec = 10;
	timeout.tv_usec = 0;

	printf("Waiting for data on FIFO(10 Seconds)....\n");

	int ret = select(fd+1,&readfds,NULL,NULL,&timeout);

	if(ret == -1)
	{
		perror("select");
		close(fd);
		exit(1);
	}
	else if(ret == 0)
	{
		printf("Timeout: No data written into FIFO within 10 seconds\n");
	}
	else
	{
		if(FD_ISSET(fd,&readfds))
		{
			int n = read(fd,buffer,sizeof(buffer));
			if(n>0)
			{
				buffer[n] = '\0';
				printf("Received from FIFO: %s\n",buffer);
			}
			else
			{
				printf("No data read(EOF or writer closed)\n");
			}
		}
	}
	close(fd);
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./22.out
	Waiting for data on FIFO(10 Seconds)....
	Received from FIFO: Hello From FIFO

	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./22.out
	Waiting for data on FIFO(10 Seconds)....
	Timeout: No data written into FIFO within 10 seconds
*/
