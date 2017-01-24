
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall #Turns on all warnings
CXXFLAGS += -pedantic-errors #Strictly enforce the standard
CXXFLAGS += -g #Debugging info
#CXXFLAGS += O3 #Optimation option

OBJS = Game.o utility.o Die.o LoadedDie.o lab3.o 
	
HEADERS = Game.hpp Die.hpp LoadedDie.hpp utility.hpp

SRCS = Game.cpp Die.cpp utility.cpp lab3.cpp LoadedDie.cpp


#target: dependencies
#	rule to build	

default: clean lab3

lab3: ${HEADERS} ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab3

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f *.o
	rm -f lab3


