#include "userlist.h"
#include "knocklistener.h"
#include "knocker.h"
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>


int main( int argc, const char* argv[] )
{
	User * list;
	pthread_t tID;
	
	list=NULL;
	
	//process the knocking listener
	pthread_create(&tID,NULL,(void *)server,NULL);
	
	//process scaning
	IPScan(&list);
	char dummy[50];
	scanf("%s",dummy);
	
}
