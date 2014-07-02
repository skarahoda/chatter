chatter: chatter.c userlist.o knocklistener.o knocker.o
	gcc chatter.c knocker.o userlist.o knocklistener.o -o chatter -lpthread
userlist: userlist.h userlist.c
	gcc -c userlist.c -o userlist.o
knocklistener: knocklistener.h knocklistener.c
	gcc -c knocklistener.c -o knocklistener.o
knocklistener: knocker.h knocker.c
	gcc -c knocker.c -o knocker.o
clean:
	rm knocker.o knocklistener.o userlist.o chatter
