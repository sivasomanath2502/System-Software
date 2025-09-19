/*
===============================================================================
Name : 16a.c
Author : Guduru Veera Siva Somanath
Description :Implement write lock
Date:04-Sep-2025
===============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
	int fd;
	struct flock lock;

	fd = open("db",O_RDWR | O_CREAT,0644);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	write(1,"Before entering the Critical Section...\n",40);
	fcntl(fd,F_SETLKW,&lock);
	write(1,"Inside the critical section...\n",31);
	write(1,"Press Enter to unlock...\n",25);
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	write(1,"Unlocked\n",9);
	close(fd);
	write(1,"Finish\n",7);
	return 0;
}

/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./writer.out
	Before entering the Critical Section...
	Inside the critical section...
	Press Enter to unlock...

	Unlocked
	Finish
*/
