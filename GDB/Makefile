CXX=g++
CXXFLAGS=-std=c++11 -Wall
TARGETS=test_no_ubsan test_ubsan test_ubsan_detail

.PHONY: all clean

all: $(TARGETS)

test_no_ubsan: overflow.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

test_ubsan: overflow.cpp
	$(CXX) $(CXXFLAGS) -fsanitize=undefined -o $@ $<

test_ubsan_detail: overflow.cpp
	$(CXX) $(CXXFLAGS) -fsanitize=undefined -g -o $@ $<

clean:
	rm -f $(TARGETS)

