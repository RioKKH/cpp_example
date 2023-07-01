GPP = g++
RM  = rm -rf
GPPFLAGS = -Wall -g3 -O3 -std=c++11

MODULE  = codetalker
INSTALL = codetalker
INSDIR = ../

.PHONY: all clean install

all: ${MODULE}

codetalker: CodeTalker.cpp
	${GPP} ${GPPFLAGS} -o $@ $<

install:
	cp -p ${MODULE} ${INSDIR} 

clean:
	${RM} ${MODULE}
	${RM} *.o
