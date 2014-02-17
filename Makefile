CC=gcc
CFLAGS=-std=gnu99 -flto -O2 -I./include

test: test_opaque test_public

test_opaque: opaque.o
	${CC} ${CFLAGS} -o bin/$@ test/test_opaque.c $^

test_public: public.o
	${CC} ${CFLAGS} -o bin/$@ test/test_public.c $^

example: opaque.o public.o
	${CC} ${CFLAGS} -o bin/$@ test/example.c $^

opaque.o:
	${CC} ${CFLAGS} -c -o $@ opaque/opaque.c

public.o:
	${CC} ${CFLAGS} -c -o $@ public/public.c

all: test example

clean:
	rm -f bin/* *.o
