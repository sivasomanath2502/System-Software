/*
===============================================================================
Name : 20Receiver.c
Author : Guduru Veera Siva Somanath
Description :   Write two programs so that both can communicate by FIFO -Use 
		one way communication.
Date: 16-Sep-2025
===============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd;
	char *fifo = "myfifo";
	char buffer[100];

	fd = open(fifo,O_RDONLY);
	if(fd == -1)
	{
		perror("open");
		exit(1);
	}

	read(fd,buffer,sizeof(buffer));
	printf("Received: %s\n",buffer);

	close(fd);
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./receiver.out
	Received: Hi i am sending this message using fifo
*/
