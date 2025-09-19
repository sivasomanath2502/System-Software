/*
===============================================================================
Name : 9.c
Author : Guduru Veera Siva Somanath
Description : 	Write a program to print the following information about a give 
		file.
Date: 15-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc,char *argv[]){
	struct stat fileStat;

	if(argc != 2)
	{
		fprintf(stderr,"Usage: %s filename\n",argv[0]);
		exit(1);
	}

	if(stat(argv[1],&fileStat)<0)
	{
		perror("stat");
		exit(1);
	}

	printf("FIle: %s\n",argv[1]);
	printf("Inode: %ld\n",(long)fileStat.st_ino);
	printf("Number of hard links: %ld\n",(long)fileStat.st_nlink);
	printf("UID: %d\n",fileStat.st_uid);
	printf("GID: %d\n",fileStat.st_gid);
	printf("Size: %ld bytes\n",(long)fileStat.st_size);
	printf("Block Size: %ld bytes\n",(long)fileStat.st_blksize);
	printf("Number of blocks: %ld\n",(long)fileStat.st_blocks);
	printf("Time of last access: %s\n",ctime(&fileStat.st_atime));
	printf("Time of last modification: %s\n",ctime(&fileStat.st_mtime));
	printf("Time of last status change: %s\n",ctime(&fileStat.st_ctime));

	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./9.out header.txt
	FIle: header.txt
	Inode: 1059196
	Number of hard links: 2
	UID: 1000
	GID: 1000
	Size: 203 bytes
	Block Size: 4096 bytes
	Number of blocks: 8
	Time of last access: Sat Sep  6 22:26:32 2025
	Time of last modification: Fri Aug 22 07:16:03 2025
	Time of last status change: Sat Sep  6 21:34:52 2025
*/
