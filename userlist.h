#ifndef USERLIST_H_
#define USERLIST_H_


typedef struct Users{
	char * name;
	char * IP;
	struct User * next;
} User;

void addUser(char * name, char * IP, User ** list);
#endif
