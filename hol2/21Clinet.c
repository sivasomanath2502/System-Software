/*
===============================================================================
Name : 21Cilent.c
Author : Guduru Veera Siva Somanath
Description :   Write two programs so that both can communicate by FIFO -Use 
		two way communications.
Date: 16-Sep-2025
===============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2;
	char message[100],buffer[100];
	fd1 = open("fifo1",O_RDONLY);
	fd2 = open("fifo2",O_WRONLY);
	if(fd1 == -1 || fd2 == -1)
	{
		perror("open fifo");
		exit(1);
	}
	while(1)
	{
		read(fd1,buffer,sizeof(buffer));
		printf("Received:%s\n",buffer);

		if(strncmp(buffer,"exit",4) == 0)
		{
			printf("\nChat Exiting....\n");
			break;
		}
		printf("Enter Reply:");
		fgets(message,sizeof(message),stdin);

		write(fd2,message,strlen(message)+1);
	}
	close(fd1);
	close(fd2);

	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./client.out
	Received:Hii

	Enter Reply:Hello
	Received:This is a chat application

	Enter Reply:Ohh Nice
	Received:exit


	Chat Exiting....
*/
