/*
===============================================================================
Name : 20Sender.c
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
#include<string.h>

int main()
{
	int fd;
	char *fifo = "myfifo";
	char message[100];

	fd = open(fifo,O_WRONLY);
	if(fd == -1)
	{
		perror("open");
		exit(1);
	}

	printf("Enter a message:");
	fgets(message,sizeof(message),stdin);

	write(fd,message,strlen(message)+1);

	close(fd);
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./sender.out
	Enter a message:Hi i am sending this message using fifo
*/
