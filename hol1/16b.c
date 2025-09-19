/*
===============================================================================
Name : 16b.c
Author : Guduru Veera Siva Somanath
Description : Implement read lock
Date: 04-Sep-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd;
	struct flock lock;

	fd = open("db",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}

	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	write(1,"Before Entring the critical section..\n",38);
	fcntl(fd,F_SETLKW,&lock);
	write(1,"Read Lock acquired. Inside Critical Section...\n",47);
	write(1,"Press Enter to unlock...\n",25);
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	write(1,"Unlocked\n",9);
	write(1,"Read lock released.\n",21);
	close(fd);
	write(1,"Finish\n",7);
	return 0;
}

/*
 Output
 	Before entering the Critical Section...
	Inside the critical section...
	Press Enter to unlock...

	Unlocked
	Finish
*/
