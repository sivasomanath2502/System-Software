/*
===============================================================================
Name : 22.c
Author : Guduru Veera Siva Somanath
Description : 	Write a program, open a file, call fork, and then write to the 
		file by both the child as well as the parent processes. Check 
		output of the file.
Date: 01-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd = open("Shared_File.txt",O_CREAT | O_WRONLY | O_TRUNC,0644);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}

	if(fork() == 0)
	{
		write(fd,"This is from Child Process\n",27);
	}
	else
	{
		write(fd,"This is from Parent Process\n",28);
	}

	close(fd);
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./22.out
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ cat Shared_File.txt
	This is from Parent Process
	This is from Child Process
*/
