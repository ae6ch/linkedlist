all:	libser.a ll-test


ll.o:	ll.h ll.c
	gcc -c ll.c -o ll.o

ll-test: ll-test.c ll.o
	gcc  ll-test.c ll.o -o ll-test

libser.a: ll.o
	rm libser.a; ar -r libser.a ll.o
