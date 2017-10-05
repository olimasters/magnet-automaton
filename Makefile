SRCDIR = src
TESTDIR = test
BINDIR = bin
BUILDDIR = build
INCLUDE = include
OBJS = $(BUILDDIR)/Main.o $(BUILDDIR)/Magnet.o
TESTOBJS = $(BUILDDIR)/Magnet_test.o $(BUILDDIR)/tester.o $(BUILDDIR)/Magnet.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -O2
LFLAGS = -Wall

.PHONY: all target tests clean

all: target tests

target: $(BINDIR)/magnet

tests: $(BINDIR)/tester

$(BINDIR)/magnet : $(OBJS)
	$(CC) $(LFLAGS) $^ -o $(BINDIR)/magnet

$(BINDIR)/tester : $(TESTOBJS)
	$(CC) $(LFLAGS) $^ -o $(BINDIR)/tester

$(BUILDDIR)/Main.o : $(SRCDIR)/Main.cpp $(SRCDIR)/Magnet.h
	$(CC) $(CFLAGS) -I$(INCLUDE) $< -o $@

$(BUILDDIR)/Magnet.o : $(SRCDIR)/Magnet.cpp $(SRCDIR)/Magnet.h
	$(CC) $(CFLAGS) -I$(INCLUDE) $< -o $@

$(BUILDDIR)/tester.o : $(TESTDIR)/tester.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) $< -o $@

$(BUILDDIR)/Magnet_test.o : $(TESTDIR)/Magnet_test.cpp $(SRCDIR)/Magnet.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -I$(SRCDIR) $< -o $@

clean:
	rm -f $(BUILDDIR)/*.o $(BINDIR)/*


