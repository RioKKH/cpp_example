CC = gcc
CPP = g++
NVCC = nvcc
GCC_OPTIONS = -Wall --pedantic-error
GPP_OPTIONS = -std=c++17 -Wall --pedantic-error -D_DEBUG
NVCC_OPTIONS = -arch=sm_52 -D_DEBUG
#NVCC_OPTIONS = -arch=sm_86 -D_DEBUG

GNUOPENMP = -fopenmp
INTELOPEMP = -openmp

APPS = main

TARGET = ${APPS}

all: ${APPS}
build: ${APPS}

Parameters.o: Parameters.cpp Parameters.hpp
	$(NVCC) $(NVCC_OPTIONS) -o $@ -c $<

CUDAkernel.o: CUDAkernel.cpp CUDAkernel.hpp
	$(NVCC) $(NVCC_OPTIONS) -o $@ -c $<

main : main.cpp Parameters.o CUDAkernel.o
	$(NVCC) $(NVCC_OPTIONS) $^ -o $@

run: build

clean:
	rm -f ${APPS} rm -f *.o

clobber: clean
