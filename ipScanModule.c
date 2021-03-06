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
#include <pthread.h>

#include "net.h"
#include "ipScanModule.h"

#define NUM_THREADS 254
void *FUNC_THREAD(void *threadid)
{
    FILE *dosya_yaz;
    dosya_yaz = fopen("userlist.txt","a");
    long tid;
    tid = (long)threadid;
    
    char str[20];
    sprintf(str,"192.168.2.%ld",(tid+1));
    
    int conn;
    conn = connect_socket(10001,str);
    char inbuffer[512];
    if (conn != -1)
	{
		recv(conn,inbuffer,512,0);
		fprintf(dosya_yaz,"%s %s\n",str,inbuffer);
		
	}
	   
    close(conn);
    
    fclose(dosya_yaz);
    pthread_exit(NULL);
}

void ipScan()
{
	remove("userlist.txt");
	pthread_t threads[NUM_THREADS];
    int rc;
    int i;
    
    for( i=0; i < NUM_THREADS; i++ )
    {
	  //printf("main() : creating thread, %d\n",i);
      
      rc = pthread_create(&threads[i], NULL,FUNC_THREAD, (void *)i);
      	  
      if (rc)
      {
		 printf("Error:unable to create thread, %d\n",rc);
         exit(1);
      }
   }
   
}


