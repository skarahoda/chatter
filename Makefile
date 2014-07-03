chatter: chatter.c knockModule.o ipScanModule.o userlist.o listener.o sender.o net.o
	gcc chatter.c ipScanModule.o knockModule.o userlist.o net.o listener.o sender.o -o chatter -lpthread
userlist: userlist.h userlist.c
	gcc -c userlist.c -o userlist.o
knockModule: knockModule.h knockModule.c net.o
	gcc -c knockModule.c net.o -o knockModule.o
listener: listener.h listener.c net.o userlist.o
	gcc -c listener.c net.o userlist.o -o listener.o
sender: sender.h sender.c net.o
	gcc -c sender.c sender.o -o listener.o
ipScanModule: ipScanModule.c ipScanModule.h net.o
	gcc -c ipScanModule.c net.o -o ipScanModule.o -lpthread
net: net.c net.h
	gcc -c net.c -o net.o
clean:
	rm *.o chatter userlist.txt
