#include "knockModule.h"
#include "ipScanModule.h"
#include "listener.h"
#include "sender.h"
#include "userlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

char * getFullLine(void) {
    char * line = malloc(100), * linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;

    if(line == NULL)
        return NULL;

    for(;;) {
        c = fgetc(stdin);
        if(c == EOF)
            break;

        if(--len == 0) {
            len = lenmax;
            char * linen = realloc(linep, lenmax *= 2);

            if(linen == NULL) {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if((*line++ = c) == '\n')
            break;
    }
    *line = '\0';
    return linep;
}

void printhelp()
{
	printf(":s\n\tscan all network to get online users.\n");
	printf(":l\n\tprint all recorded users on the LAN.\n");
	printf(":q\n\tterminate the program.\n");
	printf(":h\n\tenter the help menu.\n");
	printf("<username> <message>: send one line message to recorded username.\n");
	
}

int main( int argc, const char* argv[] )
{

	pthread_t tID;
	//process the knocking listener
	pthread_create(&tID,NULL,(void *)knock,NULL);
	pthread_create(&tID,NULL,(void *)listener,NULL);
	
	//process scaning
	ipScan();
	char username[50];
	char temp[50];
	printf("Welcome\n>");
	int c;
	while(1)
	{
		c = fgetc(stdin);
		if(c == ':')
		{
			c = fgetc(stdin);
			if(c == 'q')
				break;//quit
			else if(c == 's')
				ipScan();//Scan
			else if(c == 'h')
				printhelp();
			else if(c == 'l')
				printAll();
			else
				printf("There is no such that command\n");
			c= fgetc(stdin);
		}
		else if(c == '\n')
		{
			//do nothing
		}
		else 
		{
			scanf("%s",temp);
			username[0] = c;
			username[1] = 0;
			strcat(username, temp);
			char * IP = findUser(username);
			//find username
			if( IP != NULL)
			{
				char * msg = getFullLine();
				if(msg != NULL)
					sender(IP, msg);
			}
			else
				printf("404 NOT FOUND\n");
		}
		printf(">");
		
	};
	
	return 0;
}
