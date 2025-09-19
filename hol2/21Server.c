/*
===============================================================================
Name : 21Server.c
Author : Guduru Veera Siva Somanath
Description :   Write two programs so that both can communicate by FIFO -Use 
		two way communications.
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
	int fd1,fd2;
	char message[100],buffer[100];

	fd1 = open("fifo1",O_WRONLY);
	fd2 = open("fifo2",O_RDONLY);
	if(fd1 == -1 || fd2 == -1)
	{
		perror("open fifo");
		exit(1);
	}
	while(1)
	{
		printf("Enter Message:");
		fgets(message,sizeof(message),stdin);

		write(fd1,message,strlen(message)+1);

		if(strncmp(message,"exit",4) == 0){
			printf("\nChat Exiting.....\n");
			break;
		}

		read(fd2,buffer,sizeof(buffer));
		printf("Received:%s\n",buffer);
	}
	close(fd1);
	close(fd2);
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./server.out
	Enter Message:Hii
	Received:Hello

	Enter Message:This is a chat application
	Received:Ohh Nice

	Enter Message:exit

	Chat Exiting.....
*/
