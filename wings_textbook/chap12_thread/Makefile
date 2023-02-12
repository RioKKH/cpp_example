CPP = g++
CPP_OPTIONS = -std=c++11 -Wall -O3 -march=native
CPP_OMP = -fopenmp
#CPP_OPTIONS = -std=c++17 -Wall -O3 -march=native

PROGRAM = primes_single primes_single_better \
					primes_thread1 primes_thread2 primes_thread3 \
					primes_thread4 primes_thread5 \
					deadlock primes_openmp \
					answer1 answer2

all: $(PROGRAM)

primes-single.o: primes-single.cpp
	$(CPP) $(CPP_OPTIONS) -c $< -o $@

primes-single_better.o: primes-single_better.cpp
	$(CPP) $(CPP_OPTIONS) -c $< -o $@

primes-thread1.o : primes-thread1.cpp
	$(CPP) $(CPP_OPTIONS) -c $< -o $@

primes-thread2.o : primes-thread2.cpp
	$(CPP) $(CPP_OPTIONS) -c $< -o $@

primes-thread3.o : primes-thread3.cpp
	$(CPP) $(CPP_OPTIONS) -c $< -o $@

primes-thread4.o : primes-thread4.cpp
	$(CPP) $(CPP_OPTIONS) -c $< -o $@

primes-thread5.o : primes-thread5.cpp
	$(CPP) $(CPP_OPTIONS) -c $< -o $@

deadlock.o : deadlock.cpp
	$(CPP) $(CPP_OPTIONS) -c $< -o $@

primes-openmp.o : primes-openmp.cpp
	$(CPP) $(CPP_OPTIONS) -c $< -o $@

answer1.o : answer1.cpp
	$(CPP) $(CPP_OPTIONS) -c $< -o $@

answer2.o : answer2.cpp
	$(CPP) $(CPP_OPTIONS) -c $< -o $@

primes_single: primes-single.o
	$(CPP) -o $@ $^

primes_single_better: primes-single-better.o
	$(CPP) -o $@ $^

primes_thread1: primes-thread1.o
	$(CPP) -o $@ $^

primes_thread2: primes-thread2.o
	$(CPP) -o $@ $^

primes_thread3: primes-thread3.o
	$(CPP) -o $@ $^

primes_thread4: primes-thread4.o
	$(CPP) -o $@ $^

primes_thread5: primes-thread5.o
	$(CPP) -o $@ $^

deadlock: deadlock.o
	$(CPP) -o $@ $^

primes_openmp: primes-openmp.o
	$(CPP) $(CPP_OMP) -o $@ $^

answer1: answer1.o
	$(CPP) -o $@ $^

answer2: answer2.o
	$(CPP) -o $@ $^

clean: 
	rm -f ${PROGRAM}
	rm -f *.o
