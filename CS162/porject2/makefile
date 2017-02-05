# Author: Ryan McGinn (mostly derived from the week 1 lecture videos)
# Date: 05 February 2017
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall #Turns on all warnings
CXXFLAGS += -pedantic-errors #Strictly enforce the standard
CXXFLAGS += -g #Debugging info
#CXXFLAGS += O3 #Optimation option

OBJS = List.o utility.o Item.o project2.o 
	
HEADERS = List.hpp Item.hpp utility.hpp

SRCS = List.cpp Item.cpp utility.cpp project2.cpp


#target: dependencies
#	rule to build	

default: clean project2

project2: ${HEADERS} ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o project2

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f *.o
	rm -f project2


