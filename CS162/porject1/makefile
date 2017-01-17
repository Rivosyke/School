# This is a test of the git

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall #Turns on all warnings
CXXFLAGS += -pedantic-errors #Strictly enforce the standard
CXXFLAGS += -g #Debugging info
#CXXFLAGS += O3 #Optimation option

OBJS = utility.o ant.o project1.o
	
HEADERS = utility.hpp ant.hpp

SRCS = utility.cpp ant.cpp project1.cpp


#target: dependencies
#	rule to build	

default: project1 clean

project1: ${HEADERS} ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o project1

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f *.o
	rm -f a.out


