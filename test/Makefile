OUTNAME = inihmap

GCC = gcc
GCCFLAGS:= -O0 -ggdb -pg
INCLUDE:= -I./deps/ -I../deps

all: test

deps:
	clib install jlcordeiro/minunit

test: clean deps
	$(GCC) $(GCCFLAGS) $(INCLUDE) -c test1.c
	$(GCC) -o $(OUTNAME) test1.o ../ini.o ../map.o ../inihmap.o

clean:
	@rm -f *.o $(OUTNAME)

distclean: clean
	-@rm -rf ./deps
