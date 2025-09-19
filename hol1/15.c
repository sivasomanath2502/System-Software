/*
===============================================================================
Name : 15.c
Author : Guduru Veera Siva Somanath
Description : Write a program to display the environmental variable of the user
Date: 25-Aug-2025
===============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>

extern char **environ;

int main(){
	char **env = environ;

	while(*env){
		write(1,*env,strlen(*env));
		write(1,"\n",1);
		env++;
	}
	return 0;
}
/* 
Output
	gsomanath@gsomanath-Inspiron-15-5518:~/hol1$ ./15.out
	SHELL=/bin/bash
	SESSION_MANAGER=local/gsomanath-Inspiron-15-5518:@/tmp/.ICE-unix/2209,unix/gsomanath-Inspiron-15-5518:/tmp/.ICE-unix/2209
	QT_ACCESSIBILITY=1
	COLORTERM=truecolor
	XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
	XDG_MENU_PREFIX=gnome-
	GNOME_DESKTOP_SESSION_ID=this-is-deprecated
	GNOME_SHELL_SESSION_MODE=ubuntu
	SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
	MEMORY_PRESSURE_WRITE=c29tZSAyMDAwMDAgMjAwMDAwMAA=
	XMODIFIERS=@im=ibus
*/
	
