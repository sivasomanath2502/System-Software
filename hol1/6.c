/*
===============================================================================
Name : 6.c
Author : Guduru Veera Siva Somanath
Description :   Write a program to take input from STDIN and display on STDOUT.
		Use only read/write system calls
Date: 15-Aug-2025
===============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	char buffer[100];
	int n;

	n = read(0,buffer,sizeof(buffer));
	if(n<0){
		write(2,"Error reading input\n",20);
		exit(1);
	}
	if(write(1,buffer,n)<0){
		write(2,"Error writing output\n",21);
		exit(1);
	}
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./6.out
	Hi This Hand On List 1 Question Number 6
	Hi This Hand On List 1 Question Number 6
*/
