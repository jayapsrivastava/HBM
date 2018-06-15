WRKDIR=/home/hpcsriv1
CC=cc
CFLAGS=-g -Wall 
IDIR=$(WRKDIR)/myBuilds/memkind/include
LIB=$(WRKDIR)/myBuilds/memkind/lib

dotproduct:	dotproduct.c
	$(CC) -o dotproduct dotproduct.c -L$(LIB) -lmemkind -I$(IDIR) $(CFLAGS)

clean:	
	/usr/bin/rm -rf dotproduct 
