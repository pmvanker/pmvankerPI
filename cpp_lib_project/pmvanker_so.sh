SRCFILE=gpio.cpp
OBJFILE=gpio.o
LIBFILE=gpio.so
GCCFLAGS="-c -Wall -Werror -fpic"

# Compiling Source
echo "compiling source ..."
g++ ${GCCFLAGS} ${SRCFILE}

# Creating Dynamic lib
echo "creting Dynamic library"
g++ -shared -o ${LIBFILE} ${OBJFILE} 

# Deleting object files
echo "deleting object files"
rm -rf ${OBJFILE}