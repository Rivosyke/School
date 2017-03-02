# Author: Ryan McGinn (mostly derived from the week 1 lecture videos)
# Date: 14 February 2017
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall #Turns on all warnings
CXXFLAGS += -pedantic-errors #Strictly enforce the standard
CXXFLAGS += -g #Debugging info
#CXXFLAGS += O3 #Optimation option

OBJS = Creature.o Barbarian.o BlueMen.o HarryPotter.o Medusa.o Vampire.o Die.o utility.o CreatureList.o ListNode.o Game.o project4.o
	
HEADERS = Creature.hpp Barbarian.hpp BlueMen.hpp HarryPotter.hpp Medusa.hpp Vampire.hpp Die.hpp utility.hpp CreatureList.hpp Game.hpp

SRCS = Creature.cpp Barbarian.cpp BlueMen.cpp HarryPotter.cpp Medusa.cpp Vampire.cpp Die.cpp utility.cpp CreatureList.cpp ListNode.cpp Game.cpp project4.cpp


#target: dependencies
#	rule to build	

default: clean project4

project4: ${HEADERS} ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o project4

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f *.o
	rm -f project4


