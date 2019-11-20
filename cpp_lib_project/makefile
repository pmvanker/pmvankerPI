OBJS =  main.cpp 
CFLAG = -Wall
CC = g++
LIBS = -L. ./gpio.so

all: test
test: ${OBJ}
	   ${CC} ${CFLAGS} -o $@ ${OBJS} ${LIBS} 
clean:
	   -rm -f *.o core *.core test
.cpp.o:
	   ${CC} ${CFLAGS} -c $<
