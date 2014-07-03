#include "knockModule.h"

void knock()
{
	int s;
    int c;
    int l;

    char myname[] = "sertac-emre";

    struct sockaddr_in client_address;
    l = sizeof(client_address);
    memset(&client_address, 0, sizeof(client_address));
    s = listen_socket(10001);

    while(1)
    {
        c = accept(s, (struct sockaddr *) &client_address, &l);
        send(c, myname, strlen(myname)+1, 0);
        close(c);
    }
    close(s);
}

