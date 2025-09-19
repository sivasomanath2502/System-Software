/*
===============================================================================
Name : 8.c
Author : Guduru Veera Siva Somanath
Description : 	Write a program to open a file in read only mode, read line by 
		line and display each line as it is read.Close the file when 
		end of file is reached.
Date: 15-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int fd;
	char ch;
	char line[1024];
	int i = 0;

	if(argc != 2){
		write(2, "Usage: ./8.out <filename>\n",27);
		exit(1);
	}

	fd = open(argv[1],O_RDONLY);
	if(fd<0){
		write(2,"Error opening file.\n",19);
		exit(1);
	}

	write(1,"Press Enter to display each line:\n",35);

	while(read(fd,&ch,1)>0)
	{
		line[i++] = ch;
		if(ch == '\n')
		{
			line[i] = '\0';
			read(0,&ch,1);
			write(1,line,i);
			i = 0;
		}
	}
	if(i>0)
	{
		line[i] = '\0';
		read(0,&ch,1);
		write(1,line,i);
		i = 0;
	}
	close(fd);
	return 0;
}
/*
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./8.out records.txt
	Press Enter to display each line:
	Record1: ABCDEFGHIJKLMNOPQRSTUVWXYZ                       
	Record2: abcdefghijklmnopqrstuvwxyz                       
	Record3: 0123456789  
*/
