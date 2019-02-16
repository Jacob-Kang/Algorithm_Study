APP_NAME=algorithm
uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')

STD=-std=c++11  
WARN=-Wall -W
OPTIMIZATION?=-O0
OPT=$(OPTIMIZATION)
ifeq ($(uname_S),Darwin)
	OPT+=-DOS_MACOSX
endif

DEBUG=-g -ggdb

FINAL_CFLAGS=$(STD) $(WARN) $(OPT) $(DEBUG) $(CFLAGS) $(REDIS_CFLAGS)
FINAL_CFLAGS+= 

APP_CPP=$(CXX) $(FINAL_CFLAGS)

APP_OBJ=*.o

all: *.cpp
	$(APP_CPP) -o $(APP_NAME) $^ $(FINAL_LIBS)

clean:
	rm -rf $(APP_NAME) *.o *.dSYM