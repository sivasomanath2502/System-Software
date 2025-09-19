/*
===============================================================================
Name : 1a.c
Author : Guduru Veera Siva Somanath
Description : Create soft link (symlink system call)
Date:15-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	
	int status = 0;
	status = symlink("footer.txt","fSoftlink.txt");
	
	if(status == 0)
		printf("Soft Link created successfully.\n");
	else
		perror("symlink");
	return 0;
}

/*
Output 
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./1a.out
	Soft Link created successfully.
*/

