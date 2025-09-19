/*
===============================================================================
Name : 13.c
Author : Guduru Veera Siva Somanath
Description :   Write a program to wait for a STDIN for 10 seconds using select. 		Write a proper print statement to verify whether the data is 
		available within 10 seconds or not
Date: 25-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/select.h>
#include<string.h>

int main()
{
	fd_set readfds;
	struct timeval tv;
	int retval;

	FD_ZERO(&readfds);
	FD_SET(0,&readfds);

	tv.tv_sec = 10;
	tv.tv_usec = 0;

	write(1,"Wating for input on STDIN (10 seconds timeout)...\n",51);
	retval = select(1,&readfds,NULL,NULL,&tv);

	if(retval == -1)
	{
		write(2,"select error\n",13);
		exit(1);
	}
	else if(retval == 0)
		write(1,"No data entred within 10 secnods. Timeout!!!\n",46);
	else
	{
		if(FD_ISSET(0,&readfds)){
			write(1,"Data is available on STDIN! you typed:",39);
			char buf[1024];
			int n = read(0,buf,sizeof(buf)-1);
			if(n>0)
			{
				buf[n] = '\0';
				write(1,buf,n);
			}
		}
	}
	return 0;
}

/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./13.out
	Wating for input on STDIN (10 seconds timeout)...
	hfbdsdbfgsdvf
	Data is available on STDIN! you typed:hfbdsdbfgsdvf
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./13.out
	Wating for input on STDIN (10 seconds timeout)...
	No data entred within 10 secnods. Timeout!!!
*/
