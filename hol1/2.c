/*
===============================================================================
Name : 2.c
Author : Guduru Veera Siva Somanath
Description :   Write a simple program to execute in an infinite loop at the 
		background. Go to /proc directory and identify all the process 
		related information in the corresponding proc directory.
Date: 15-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	while(1)
	{

	}
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:/proc/4721$ cat status
	Name:	2.out
	Umask:	0002
	State:	R (running)
	Tgid:	4721
	Ngid:	0
	Pid:	4721
	PPid:	3047
	TracerPid:	0
	Uid:	1000	1000	1000	1000
	Gid:	1000	1000	1000	1000
	FDSize:	256
*/


