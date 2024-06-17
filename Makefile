CC = g++
NVCC = nvcc
GCC_OPTIONS = -std=c++17 -Wall --pedantic-error

PROGRAM = recursive_fibonacci to_check_limit_of_int usage_of_pointer\
	  pointer_of_pointer enum_with_scope

all : $(PROGRAM)

# $@ file name of the target
# $< file name of the most-left predefined
# $^ all file name of predefined

all.h.gch : all.h
	$(CC) $(GCC_OPTIONS) -x c++-header -o $@ $<

recursive_fibonacci : recursive_fibonacci.cpp all.h
	$(CC) $(GCC_OPTIONS) $< -o $@

to_check_limit_of_int : to_check_limit_of_int.cpp all.h
	$(CC) $(GCC_OPTIONS) $< -o $@

usage_of_pointer : usage_of_pointer.cpp all.h
	$(CC) $(GCC_OPTIONS) $< -o $@

pointer_of_pointer : pointer_of_pointer.cpp all.h
	$(CC) $(GCC_OPTIONS) $< -o $@

enum_with_scope : enum_with_scope.cpp all.h
	$(CC) $(GCC_OPTIONS) $< -o $@
