CPP = g++
GPPOPTIONS = -std=c++17 -Wall --pedantic-error

APPS = test

all: ${APPS}
build: ${APPS}

lib.o: lib.cpp
	$(CPP) $(GPPOPTIONS) -o $@ -c $<

test: main.cpp lib.o
	$(CPP) $(GPPOPTIONS) $^ -o $@
