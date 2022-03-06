CC = gcc
CPP = g++

CC_OPTIONS = -Wall --pedantic-error
CPP_OPTIONS = -std=c++17 -Wall --pedantic-error

PROGRAM = main

all : $(PROGRAM)

main.o : main.c
	# $(CC) -c -o $@ $<
	$(CC) $(CC_OPTIONS) -c $< -o $@
	# $(CC) $(GCC_OPTIONS) -c $< -o $@
	# $(CC) $(GCC_OPTIONS) -c $< -o $@

call_cpp.o : call_cpp.cpp
	$(CPP) -c -o $@ $<
	# $(CPP) $(GCC_OPTIONS) -c $< -o $@

main : main.o call_cpp.o
	$(CPP) -o $@ $^
	# $(CPP) $(GCC_OPTIONS) -o $@ $^

clean :
	rm -f {PROGRAM}
	rm -f *.o
