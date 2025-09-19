/*
===============================================================================
Name : 1b.c
Author : Guduru Veera Siva Somanath
Description : Create a hard link (link system call)
Date: 15-Aug-2025
===============================================================================
*/


#include<stdio.h>
#include<unistd.h>

int main(){
	int status;

	status = link("header.txt","hHardlink.txt");

	if(status == 0)
		printf("Hard link created successfully\n");
	else
		perror("link");
	return 0;
}

/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./1b.out
	Hard link created successfully
	
*/

