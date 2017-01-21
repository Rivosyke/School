# Author: Ryan McGinn (mostly derived from the week 1 lecture videos)
# Date: 21 January 2017

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall #Turns on all warnings
CXXFLAGS += -pedantic-errors #Strictly enforce the standard
CXXFLAGS += -g #Debugging info
#CXXFLAGS += O3 #Optimation option

OBJS = utility.o ant.o board.o project1.o 
	
HEADERS = utility.hpp ant.hpp board.hpp

SRCS = utility.cpp ant.cpp board.cpp project1.cpp


#target: dependencies
#	rule to build	

default: clean project1

project1: ${HEADERS} ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o project1

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f *.o
	rm -f project1


