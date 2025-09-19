/*
===============================================================================
Name : 11a.c
Author : Guduru Veera Siva Somanath
Description :   Write a program to open a file, duplicate the file descriptor 
		and append the file with both the descriptors and check whether 		the file is updated properly or not.
		a. use dup
Date: 25-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd,fd_dup;
	ssize_t n;

	fd = open("dupFile.txt",O_WRONLY | O_CREAT | O_APPEND, 0644);
	if(fd<0){
		perror("open");
		exit(1);
	}
	fd_dup = dup(fd);
	if(fd_dup<0){
		perror("dup");
		close(fd);
		exit(1);
	}

	n = write(fd,"Original FD\n",12);
	if(n<0)
		perror("write fd");

	n = write(fd_dup,"Duplicated FD\n",14);
	if(n<0)
		perror("write fd_dup");
	close(fd);
	close(fd_dup);

	printf("Data appended using dup\n");
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./11a.out
	Data appended using dup
*/
