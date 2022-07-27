GPP = g++
OPTIONS = --std=c++11 -Wall

TARGET = test

all: ${TARGET}

test.o: test.cpp
	${GPP} ${OPTIONS} -o $@ -c $<

test: main.cpp test.o
	${GPP} ${OPTIONS} $^ -o $@

clean:
	rm -rf ${TARGET}
	rm -rf *.o

