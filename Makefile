OBJS = Main.o Magnet.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -O2
LFLAGS = -Wall

magnet : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o magnet

Main.o : Main.cpp Magnet.h
	$(CC) $(CFLAGS) Main.cpp

Magnet.o : Magnet.cpp Magnet.h
	$(CC) $(CFLAGS) Magnet.cpp

clean:
	\rm *.o magnet


