/*
===============================================================================
Name : 10.c
Author : Guduru Veera Siva Somanath
Description : 	Write a program to open a file with read write mode, write 10 
		bytes, move the file pointer by 10 bytes (use lseek) and write 
		again 10 bytes.
		a. check the return value of lseek
		b. open the file with od and check the empty spaces in between 
		the data.
Date : 15-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd;
	ssize_t n;
	off_t pos;

	fd = open("testFile.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(fd<0){
		perror("open");
		exit(1);
	}
	
	n = write(fd,"AAAAAAAAAA",10);
	if(n<0){
		perror("write");
		close(fd);
		exit(1);
	}
	printf("Wrote %ld bytes\n",(long)n);

	pos = lseek(fd,10,SEEK_CUR);
	if(pos == (off_t)-1){
		perror("lseek");
		close(fd);
		exit(1);
	}
	printf("File pointer moved to position: %ld\n",(long)pos);
	
	n = write(fd,"BBBBBBBBBB",10);
	if(n<0){
		perror("write");
		close(fd);
		exit(1);
	}
	printf("Wrote %ld bytes\n",(long)n);

	close(fd);
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./10.out
	Wrote 10 bytes
	File pointer moved to position: 20
	Wrote 10 bytes
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ od -c testFile.txt
	0000000   A   A   A   A   A   A   A   A   A   A  \0  \0  \0  \0  \0  \0
	0000020  \0  \0  \0  \0   B   B   B   B   B   B   B   B   B   B
	0000036
*/
