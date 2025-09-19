/*
===============================================================================
Name : 4.c
Author : Guduru Veera Siva Somanath
Description :   Write a program to open an existing file with read write mode. 
		Try O_EXCL flag also.
Date: 15-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd;

	fd = open("myfile.txt", O_RDWR);
	if(fd == -1)
		perror("open O_RDWR");
	else
	{
		printf("Opened myfile.txt with FD = %d (O_RDWR)\n",fd);
		close(fd);
	}

	fd = open("myfile.txt", O_CREAT | O_EXCL | O_RDWR, 0666);
	if(fd == -1)
		perror("open O_CREAT | O_EXCL | O_RDWR");
	else{
		printf("Created new myfile.txt with FD = %d\n",fd);
	}
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./4.out
	open O_RDWR: No such file or directory
	Created new myfile.txt with FD = 3
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./4.out
	Opened myfile.txt with FD = 3 (O_RDWR)
	open O_CREAT | O_EXCL | O_RDWR: File exists
*/
