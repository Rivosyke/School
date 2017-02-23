# Author: Ryan McGinn (mostly derived from the week 1 lecture videos)
# Date: 26 February 2017
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall #Turns on all warnings
CXXFLAGS += -pedantic-errors #Strictly enforce the standard
CXXFLAGS += -g #Debugging info
#CXXFLAGS += O3 #Optimation option

OBJS = utility.o lab7.o Queue.o
	
HEADERS = utility.hpp Queue.hpp

SRCS = utility.cpp lab7.cpp Queue.cpp


#target: dependencies
#	rule to build	

default: clean lab7

lab7: ${HEADERS} ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab7

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f *.o
	rm -f lab7


