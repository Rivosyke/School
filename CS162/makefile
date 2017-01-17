# Author: Ryan McGinn (mostly derived from the week 1 lecture videos)
# Date: 14 January 2017

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall #Turns on all warnings
CXXFLAGS += -pedantic-errors #Strictly enforce the standard
CXXFLAGS += -g #Debugging info
#CXXFLAGS += O3 #Optimation option

OBJS = determinant.o readMatrix.o lab1.o

HEADERS = readMatrix.hpp determinant.hpp

SRCS = determinant.cpp readMatrix.cpp lab1.cpp


#target: dependencies
#	rule to build   

default: clean lab1

lab1: ${HEADERS} ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab1

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f *.o
	rm -f lab1
	rm -f a.out
