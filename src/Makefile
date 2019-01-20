CC = g++
CFLAGS  = -g -Wall -pedantic

default: cshop

cshop: cshop.o Person.o Item.o  
	$(CC) $(CFLAGS) -o cshop cshop.o Person.o Item.o

cshop.o:  cshop.cpp Person.cpp Item.cpp
	$(CC) $(CFLAGS) -c cshop.cpp Person.cpp Item.cpp

counter.o:  Item.cpp Item.h 
	$(CC) $(CFLAGS) -c Item.cpp

scanner.o:  Person.cpp Person.h 
	$(CC) $(CFLAGS) -c Person.cpp

navigator.o:  Navigator.cpp Navigator.h       
	$(CC) $(CFLAGS) -c Navigator.cpp

clean: 
	$(RM) count *.o *~
