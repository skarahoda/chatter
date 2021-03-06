#include "listener.h"
#include "userlist.h"

void listener()
{
	int s;
    int c;
    int l;

    struct sockaddr_in client_address;
    l = sizeof(client_address);
    memset(&client_address, 0, sizeof(client_address));
    s = listen_socket(10002);

	char inbuffer [512];
	char * name;
    while(1)
    {
    	
    	memset(inbuffer, 0, 512);
        c = accept(s, (struct sockaddr *) &client_address, &l);
        recv(c,inbuffer,512,0);
        name = findName(inet_ntoa(client_address.sin_addr));
        if(name != NULL)
        	printf(">>>%s: %s>",name, inbuffer);
        else
        	printf(">>>unknown user: %s>", inbuffer);
        fflush(stdout);
        close(c);
    }
    close(s);
}

