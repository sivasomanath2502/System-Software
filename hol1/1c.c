/*
===============================================================================
Name : 1c.c
Author : Guduru Veera Siva Somanath
Description :Create a FIFO (mkfifo library Function or mknod system call)
Date: 15-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
	int status;

	status = mkfifo("myPipe",0666);
	if(status == 0)
		printf("FIFO created successfully\n");
	else
		perror("mkfifo");
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./1c.out
	FIFO created successfully
*/

