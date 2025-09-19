#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd;
	int ticket = 100;

	fd = open("ticket.txt",O_RDWR | O_CREAT | O_TRUNC,0666);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	
	dprintf(fd,"%d\n",ticket);
	close(fd);

	write(1,"Initialized ticket number to 100\n",33);

	return 0;		
}
