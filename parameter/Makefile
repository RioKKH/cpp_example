GPP = g++
NVCC = nvcc

#GPP_OPTIONS = -std=c++11 -Wall
GPP_OPTIONS = -std=c++14 -Wall
NVCC_OPTIONS = -arch=sm_52
DEBUG = -D_DEBUG

TARGET = prmtest

all: ${TARGET}

Parameters.o: Parameters.cpp
	${GPP} ${GPP_OPTIONS} -o $@ -c $<

CrosstalkMap.o: CrosstalkMap.cpp
	${GPP} ${GPP_OPTIONS} -o $@ -c $<

Tools.o: Tools.cpp
	${GPP} ${GPP_OPTIONS} -o $@ -c $<

prmtest : main.cpp Parameters.o Tools.o CrosstalkMap.o
	${GPP} ${GPP_OPTIONS} $^ -o $@

clean:
	rm -f ${TARGET}
	rm -f *.o




