CC = gcc
CPP = g++
NVCC = nvcc
GCC_OPTIONS = -Wall --pedantic-error
GPP_OPTIONS = -std=c++17 -Wall --pedantic-error -D_DEBUG
NVCC_OPTIONS = -arch=sm_50
# NVCC_OPTIONS = -arch=sm_52 -D_TREND
# NVCC_OPTIONS = -arch=sm_86 -D_TREND
# NVCC_OPTIONS = -arch=sm_86 -D_DEBUG -D_TREND
# NVCC_OPTIONS = --device-c -arch=sm_86 -D_DEBUG

GNUOPENMP = -fopenmp
INTELOPEMP = -openmp

APPS = rand uniform

TARGET = ${APPS}

all: ${APPS}
build: ${APPS}

#Parameters.o: Parameters.cu
#	$(NVCC) $(NVCC_OPTIONS) -o $@ -c $<
#
#CUDAKernels.o: CUDAKernels.cu
#	$(NVCC) $(NVCC_OPTIONS) -o $@ -c $<
#
#Misc.o: Misc.cu
#	$(NVCC) $(NVCC_OPTIONS) -o $@ -c $<

CUDAKernels.o : CUDAKernels.cu
	$(NVCC)  $(NVCC_OPTIONS) -c $< -o $@

rand : main.cu CUDAKernels.o
	$(NVCC)  $(NVCC_OPTIONS) $^ -o $@

uniform : uniform.cpp
	${CPP} ${GPP_OPTIONS} $^ -o $@

run: build

clean:
	rm -f ${APPS}
	rm -f *.o

clobber: clean
