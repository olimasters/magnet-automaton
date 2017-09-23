SRCDIR = src
BINDIR = bin
BUILDDIR = build
OBJS = $(BUILDDIR)/Main.o $(BUILDDIR)/Magnet.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -O2
LFLAGS = -Wall

$(BINDIR)/magnet : $(OBJS)
	$(CC) $(LFLAGS) $^ -o $(BINDIR)/magnet

$(BUILDDIR)/Main.o : $(SRCDIR)/Main.cpp $(SRCDIR)/Magnet.h
	$(CC) $(CFLAGS) $< -o $@

$(BUILDDIR)/Magnet.o : $(SRCDIR)/Magnet.cpp $(SRCDIR)/Magnet.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	\rm $(BUILDDIR)/*.o $(BINDIR)/magnet


