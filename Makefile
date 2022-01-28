PROGRAMS = change

CC = cc
CFLAGS=-Wall -Wextra -O3 -std=c17 -pedantic `pkg-config --cflags glib-2.0`
LIBS=`pkg-config --libs glib-2.0`

all: $(PROGRAMS)

.c: ; $(CC) $(CFLAGS) $@.c $(LIBS) -o $@
	strip $@

clean:
	rm $(PROGRAMS)
