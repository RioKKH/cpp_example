CC = gcc
CPP = g++

GCC_OPTIONS = -std=c++17 -Wall --pedantic-error

PROGRAM = call_cpp

all : $(PROGRAM)

main.o : main.c
	$(CC) $(GCC_OPTIONS) -c $^ -o $@
	#$(CC) $(GCC_OPTIONS) -c $< -o $@

call_cpp.o : call_cpp.cpp
	$(CPP) $(GCC_OPTIONS) $^ -o $@

main : main.o call_cpp.o
	$(CPP) $(GCC_OPTIONS) $^ -o $@
