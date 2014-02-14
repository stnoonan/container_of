CC=clang
CFLAGS=-std=gnu99 -O2 -I./include

test: test_opaque test_public

test_opaque: opaque.o
	${CC} ${CFLAGS} -o bin/test_opaque test/test_opaque.c opaque.o

test_public: public.o
	${CC} ${CFLAGS} -o bin/test_public test/test_public.c public.o

example: opaque.o public.o
	${CC} ${CFLAGS} -o bin/example test/example.c public.o opaque.o

opaque.o:
	${CC} ${CFLAGS} -c -o opaque.o opaque/opaque.c

public.o:
	${CC} ${CFLAGS} -c -o public.o public/public.c

all: test example

clean:
	rm -f bin/* *.o
