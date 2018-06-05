WRKDIR=/home/hpcsriv1
CC=cc
CFLAGS=-g -Wall 
IDIR=$(WRKDIR)/myBuilds/memkind/include
LIB=$(WRKDIR)/myBuilds/memkind/lib

ddr:	ddr_dotproduct.c
	$(CC) -o ddr_dotproduct ddr_dotproduct.c $(CFLAGS)

hbm:	hbm_dotproduct.c
	$(CC) -o hbm_dotproduct hbm_dotproduct.c -L$(LIB) -lmemkind -I$(IDIR) $(CFLAGS)

clean:	
	/usr/bin/rm -rf ddr_dotproduct hbm_dotproduct
