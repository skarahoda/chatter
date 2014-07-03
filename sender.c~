#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>


#include "net.h"
#include "sender.h"

void sender(char * IP, char * msg)
{   
  	int conn;
  	conn = connect_socket(10002,IP);
    	if (conn != -1)
	{
		send(conn, msg, strlen(msg)+1, 0);
	}   
    	close(conn);
}


