GPP = g++
GPP_OPTIONS = -std=c++14 -Wall -v
# GPP_OPTIONS = --std=cxx

TARGET = test
all: ${TARGET}

Tools.o: Tools.cpp
	${GPP} ${GPP_OPTIONS} -o $@ -c $<

#test: main.cpp
test: main.cpp Tools.o
	${GPP} ${GPP_OPTIONS} $^ -o $@

clean:
	rm -f ${TARGET}
	rm -f *.o
