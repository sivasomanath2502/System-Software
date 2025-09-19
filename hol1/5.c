/*
===============================================================================
Name : 5.c
Author : Guduru Veera Siva Somanath
Description :   Write a program to create five new files with infinite loop. 
		Execute the program in the background and check the file 
		descriptor table at /proc/pid/fd.
Date: 15-Aug-2025
===============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd[5];
	char *filename[5] = {"f1.txt","f2.txt","f3.txt","f4.txt","f5.txt"};
	for(int i=0;i<5;i++)
	{
		fd[i] = open(filename[i], O_CREAT | O_RDWR, 0666);
		if(fd[i] == -1)
			perror("open");
		else
			printf("Created %s with FD = %d\n",filename[i],fd[i]);
	}
	while(1)
	{
		sleep(1);
	}
	return 0;
}

/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./5.out &
	[1] 5045
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ls -l /proc/5045/fd
	total 0
	lrwx------ 1 gsomanath gsomanath 64 Sep  6 22:12 0 -> /dev/pts/0
	lrwx------ 1 gsomanath gsomanath 64 Sep  6 22:12 1 -> /dev/pts/0
	lrwx------ 1 gsomanath gsomanath 64 Sep  6 22:12 2 -> /dev/pts/0
	lrwx------ 1 gsomanath gsomanath 64 Sep  6 22:12 3 -> /home/gsomanath/hol1/f1.txt
	lrwx------ 1 gsomanath gsomanath 64 Sep  6 22:12 4 -> /home/gsomanath/hol1/f2.txt
	lrwx------ 1 gsomanath gsomanath 64 Sep  6 22:12 5 -> /home/gsomanath/hol1/f3.txt
	lrwx------ 1 gsomanath gsomanath 64 Sep  6 22:12 6 -> /home/gsomanath/hol1/f4.txt
	lrwx------ 1 gsomanath gsomanath 64 Sep  6 22:12 7 -> /home/gsomanath/hol1/f5.tx
*/
