GPP = g++
RM  = rm -rf
GPPFLAGS = -Wall -g3 -o2 -std=c++11

MODULE  = encoder decoder
INSTALL = encoder decoder
INSDIR = ../

.PHONY: all clean install

all: ${MODULE}

encoder: encoder.cpp
	${GPP} ${GPPFLAGS} -o $@ $<

decoder: decoder.cpp
	${GPP} ${GPPFLAGS} -o $@ $<

install:
	cp -p ${MODULE} ${INSDIR} 

clean:
	${RM} ${MODULE}
	${RM} *.o
