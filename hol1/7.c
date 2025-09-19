/*
===============================================================================
Name : 7.c
Author : Guduru Veera Siva Somanath
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 15-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[]){
	int fd1,fd2;
	char buf[1024];
	int n;

	if(argc != 3)
	{
		write(2,"Usage: ./7.out <file1> <file2>\n",30);
		exit(1);
	}

	fd1 = open(argv[1],O_RDONLY);
	if(fd1<0){
		perror("open Source");
		exit(1);
	}

	fd2 = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd2<0)
	{
		perror("open dest");
		close(fd1);
		exit(1);
	}

	while((n = read(fd1,buf,sizeof(buf)))>0){
		if(write(fd2,buf,n) != n){
			perror("write");
			close(fd1);
			close(fd2);
			exit(1);
		}
	}
	if(n<0){
		perror("read");
	}
	close(fd1);
	close(fd2);

	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./7.out file1.txt file2.txt
*/
