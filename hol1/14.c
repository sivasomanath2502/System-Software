/*
===============================================================================
Name : 14.c
Author : Guduru Veera Siva Somanath
Description : 	Write a program to find the type of a file.
		a. Input should be taken from command line.
		b. program should be able to identify any type of a file.
Date: 25-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc,char *argv[])
{
	struct stat st;
	char *msg;
	if(argc != 2)
	{
		msg = "Usage: ./14.out filename\n";
		write(2,msg,strlen(msg));
		exit(1);
	}

	if(stat(argv[1],&st) == -1){
		msg = "Error: could not stat file\n";
		write(2,msg,strlen(msg));
		exit(1);
	}
	if(S_ISREG(st.st_mode))
		msg = "It is a regular file\n";
	else if(S_ISDIR(st.st_mode))
		msg = "It is a directory\n";
	else if(S_ISLNK(st.st_mode))
		msg = "It is a link file\n";
	else if(S_ISBLK(st.st_mode))
		msg = "It is block device file\n";
	else if(S_ISFIFO(st.st_mode))
		msg = "It is a FIFO/Pipe\n";
	else if(S_ISSOCK(st.st_mode))
		msg = "It is a socket file\n";
	else
		msg = "Unknown file type\n";

	write(1,msg,strlen(msg));
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./14.out file1.txt
	It is a regular file
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./14.out /home/gsomanath/hol1/advanced
	It is a directory
*/
