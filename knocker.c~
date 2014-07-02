#include "knocker.h"
#include "userlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void errorMessage(const char *msg)
{
	perror(msg);
	exit(0);
}

int IPScan(User ** list)
{
	int sockfd, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[256];
    
	char serverAddress[15];
	
	int i;
	for(i=45;i<255;i++)
	{	
		printf("%d\n",i);
		
		//open socket
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		
		//socket error
		if (sockfd < 0)
			errorMessage("ERROR opening socket");
		
		//set the IP address of host
		sprintf(serverAddress,"192.168.2.%d",i);
		server = gethostbyname(serverAddress);
		
		bzero((char *) &serv_addr, sizeof(serv_addr));
		serv_addr.sin_family = AF_INET;
		bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
		serv_addr.sin_port = htons(10001);
		if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) >= 0) {
			//read the username
			bzero(buffer,256);
			n = read(sockfd,buffer,255);
			if (n > 0) 
				addUser(buffer, serverAddress, list);
		}
		close(sockfd);
	}
	
	return 0;
}
