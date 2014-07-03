#ifndef USERLIST_H_
#define USERLIST_H_


typedef struct Users{
	char IP[20];
	char name[20];
} User;

char * findUser(char * name);
char * findName(char * IP);
void printAll();
#endif
