# Author: Ryan McGinn (mostly derived from the week 1 lecture videos)
# Date: 20 March 2017
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall #Turns on all warnings
CXXFLAGS += -pedantic-errors #Strictly enforce the standard
CXXFLAGS += -g #Debugging info
#CXXFLAGS += O3 #Optimation option

OBJS = utility.o Space.o final.o
	
HEADERS = utility.hpp Space.hpp

SRCS = utility.cpp Space.cpp final.cpp


#target: dependencies
#	rule to build	

default: clean final

final: ${HEADERS} ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o final

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f *.o
	rm -f final


