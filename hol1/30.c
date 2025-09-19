/*
===============================================================================
Name : 30.c
Author : Guduru Veera Siva Somanath
Description :   Write a program to run a script at a specific time using a 
		Daemon process.
Date:04-Sep-2025
===============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>

int main()
{
	pid_t pid = fork();
	if(pid<0)
		exit(EXIT_FAILURE);
	if(pid>0)
		exit(EXIT_SUCCESS);
	if(setsid() < 0)
		exit(EXIT_FAILURE);

	chdir("/");
	umask(0);

	while(1)
	{
		time_t t = time(NULL);
		struct tm *tm_info = localtime(&t);

		if(tm_info->tm_hour == 23 && tm_info->tm_min == 55)
		{
			system("/home/gsomanath/hol1/script.sh");
			sleep(60);
		}
		sleep(30);
	}
	return 0;
}

/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ cat daemon_log.txt
	Script executed at Sat Sep  6 11:55:27 PM IST 2025
*/
