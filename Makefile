all:	libser.a


ll.o:	ll.h ll.c
	gcc -O3 -c ll.c -o ll.o

libser.a: ll.o
	rm libser.a; ar -r libser.a ll.o
