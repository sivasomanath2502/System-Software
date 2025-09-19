/*
===============================================================================
Name : 3.c
Author : Guduru Veera Siva Somanath
Description :   Write a program to create a file and print the file descriptor 
		value. Use creat ( ) system call
Date: 15-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd;

	fd = creat("file1.txt",0666);

	if(fd == -1)
	{
		perror("creat");
		return 1;
	}
	printf("File created successfullt. File descriptor = %d\n",fd);
	close(fd);
	fd = creat("file2.txt",0666);
        if(fd == -1)
        {
                perror("creat");
                return 1;
        }
        printf("File created successfullt. File descriptor = %d\n",fd);
	int fd1;
	fd1 = creat("file3.txt",0666);
	if(fd1 == -1)
        {
                perror("creat");
                return 1;
        }
        printf("File created successfullt. File descriptor = %d\n",fd1);

	close(fd);
	close(fd1);
	return 0;
}

/* 
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./3.out
	File created successfullt. File descriptor = 3
	File created successfullt. File descriptor = 3
	File created successfullt. File descriptor = 4
*/
