/*
===============================================================================
Name : 16.c
Author : Guduru Veera Siva Somanath
Description :   Write a program to send and receive data from parent to child 
		vice versa. Use two way communication.
Date: 15-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
	int fd1[2];
	int fd2[2];

	char parent_msg[] = "Hello Child, This is parent";
	char child_msg[] = "Hello Parent, This is child";
	char buffer[100];

	if(pipe(fd1) == -1 || pipe(fd2) == -1)
	{
		perror("pipe failed");
		exit(1);
	}

	if(fork() == 0)
	{
		close(fd1[1]);
		close(fd2[0]);

		read(fd1[0],buffer,sizeof(buffer));
		printf("Child received: %s\n",buffer);

		write(fd2[1],child_msg,strlen(child_msg)+1);

		close(fd1[0]);
		close(fd2[1]);
	}
	else
	{
		close(fd1[0]);
		close(fd2[1]);

		write(fd1[1],parent_msg,strlen(parent_msg)+1);
		close(fd1[1]);

		read(fd2[0],buffer,sizeof(buffer));
		printf("Parent received: %s\n",buffer);

		close(fd2[0]);
		wait(NULL);
	}
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol2$ ./16.out
	Child received: Hello Child, This is parent
	Parent received: Hello Parent, This is child
*/
