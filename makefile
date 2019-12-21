CC=g++
DEBUG=false
CFLAGS=-Wall -ansi -pedantic -std=c++11
ifeq ($(DEBUG), true)
    CFLAGS+=-g -DMAP
endif
LDFLAGS=-g
SRC=Main.cpp Controller.cpp Document.cpp FileManager.cpp Log.cpp LogFactory.cpp LogManager.cpp
OBJ=$(SRC:.cpp=.o)

apachelog: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o
