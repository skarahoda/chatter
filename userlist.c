#include "userlist.h"
#include <string.h>
#include <stdlib.h>

void addUser(char * name, char * IP, User ** list)
{
	User * ptr;
	ptr = malloc(sizeof(User));
	ptr->name = malloc(50 * sizeof(char));
	ptr->IP = malloc(50 * sizeof(char));
	ptr->next = *list;
	strcpy(ptr->name, name);
	strcpy(ptr->IP, IP);
	*list=ptr;
}
