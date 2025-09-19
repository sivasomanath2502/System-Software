/*
===============================================================================
Name : 11c.c
Author : Guduru Veera Siva Somanath
Description : 	Write a program to open a file, duplicate the file descriptor 
		and append the file with both the descriptors and check whether 		the file is updated properly or not.
		c. use fcntl
Date: 25-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd,fd_fcntl;
	ssize_t n;

	fd = open("fcntlFile.txt",O_WRONLY | O_CREAT | O_APPEND,0644);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	fd_fcntl = fcntl(fd,F_DUPFD,0);
	if(fd_fcntl<0)
	{
		perror("fcntl");
		close(fd);
		exit(1);
	}

	write(fd,"Original FD fcntl\n",18);
	write(fd_fcntl,"Duplicated FD fcntl\n",20);

	close(fd);
	close(fd_fcntl);

	printf("Data appended using fcntl(F_DUPFD)\n");
	return 0;
}

/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./11c.out
	Data appended using fcntl(F_DUPFD)
*/

