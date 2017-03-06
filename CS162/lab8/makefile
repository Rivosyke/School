# Author: Ryan McGinn (mostly derived from the week 1 lecture videos)
# Date: 14 February 2017
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall #Turns on all warnings
CXXFLAGS += -pedantic-errors #Strictly enforce the standard
CXXFLAGS += -g #Debugging info
#CXXFLAGS += O3 #Optimation option

OBJS = utility.o lab8.o 
	
HEADERS = utility.hpp

SRCS = utility.cpp lab8.cpp


#target: dependencies
#	rule to build	

default: clean lab8

lab8: ${HEADERS} ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab8

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f *.o
	rm -f lab8


