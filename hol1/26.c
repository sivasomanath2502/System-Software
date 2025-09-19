/*
===============================================================================
Name : 26.c
Author : Guduru Veera Siva Somanath
Description :
Date:
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	printf("Executing ./26Helper.out with input any Name\n");
	
	char name[100];
	scanf("%s",name);

	execl("./26Helper.out",argv[0],name,(char *)NULL);

	perror("excel failed");
	return 1;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./26.out
	Executing ./26Helper.out with input any Name
	Siva
	Hello Siva
*/
