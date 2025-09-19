/*
===============================================================================
Name : 11b.c
Author : Guduru Veera Siva Somanath
Description : 	Write a program to open a file, duplicate the file descriptor 
		and append the file with both the descriptors and check whether 		the file is updated properly or not.
		b. use dup2
Date: 25-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd,fd_dup2;
	ssize_t n;

	fd = open("dup2File.txt",O_WRONLY | O_CREAT | O_APPEND,0644);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}

	fd_dup2 = dup2(fd,10);
	if(fd_dup2<0)
	{
		perror("dup2");
		close(fd);
		exit(1);
	}

	write(fd,"Original FD dup2\n",17);
	write(fd_dup2,"Duplicated FD dup2\n",19);

	close(fd);
	close(fd_dup2);

	printf("Data append using dup2\n");
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./11b.out
	Data append using dup2
*/

