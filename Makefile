GCC := gcc
GCCFLAGS:= -Werror -Wall -Wextra -pedantic -D_POSIX_SOURCE -D_GNU_SOURCE -std=c99 \
	-Wno-missing-braces -Wextra -Wformat=2 \
	-Wswitch-default -Wswitch -Wcast-align -Wpointer-arith \
	-Wundef -Wcast-qual -Wshadow -Winline \
	-Wfloat-equal -Wstrict-aliasing=2 -Wredundant-decls \
	-fno-omit-frame-pointer -ffloat-store -fno-common -fstrict-aliasing \
	-Wconversion -Wno-missing-field-initializers

GCCEXTRAFLAGS := $(shell expr `$(GCC) -dumpversion` \>= 4.6)
ifeq "$(GCCEXTRAFLAGS)" "1"
	GCCFLAGS += -Wlogical-op -Wstrict-overflow=5 -Wunreachable-code
endif

GCCFLAGS+= -O0 -ggdb -pg
INCLUDES:= -I./deps

all: inihmap

deps:
	clib install clibs/inih jlcordeiro/cmap

inih: deps
	$(GCC) $(GCCFLAGS) $(INCLUDES) -c deps/inih/ini.c

cmap: deps
	$(GCC) $(GCCFLAGS) $(INCLUDES) -c deps/cmap/map.c

inihmap: inih cmap inihmap.c
	$(GCC) $(GCCFLAGS) $(INCLUDES) -c inihmap.c

tests: inihmap
	make -C test

clean:
	-@rm *.o inihmap

distclean: clean
	-@rm -rf deps

format:
	astyle --options=$(HOME)/.astyle_format.conf *.c *.h
