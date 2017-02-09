# Author: Ryan McGinn (mostly derived from the week 1 lecture videos)
# Date: 09 February 2017
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall #Turns on all warnings
CXXFLAGS += -pedantic-errors #Strictly enforce the standard
CXXFLAGS += -g #Debugging info
#CXXFLAGS += O3 #Optimation option

OBJS = functions.o utility.o lab5.o 
	
HEADERS = functions.hpp utility.hpp

SRCS = functions.cpp utility.cpp lab5.cpp


#target: dependencies
#	rule to build	

default: clean lab5

lab5: ${HEADERS} ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab5

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f *.o
	rm -f lab5


