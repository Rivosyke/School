# Author: Ryan McGinn (mostly derived from the week 1 lecture videos)
# Date: 20 March 2017
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall #Turns on all warnings
CXXFLAGS += -pedantic-errors #Strictly enforce the standard
CXXFLAGS += -g #Debugging info
#CXXFLAGS += O3 #Optimation option

OBJS = utility.o Space.o CryoChamber.o Item.o Player.o Game.o Corridor.o CommonRoom.o StorageRoom.o Cockpit.o Airlock.o final.o CargoHold.o O2Room.o Engineering.o
	
HEADERS = utility.hpp Space.hpp CryoChamber.hpp Item.hpp Player.hpp Game.hpp Corridor.hpp CommonRoom.hpp StorageRoom.hpp Cockpit.hpp Airlock.hpp CargoHold.hpp O2Room.hpp Engineering.hpp

SRCS = utility.cpp Space.cpp final.cpp CryoChamber.cpp Item.cpp Player.cpp Game.cpp Corridor.cpp CommonRoom.cpp StorageRoom.cpp Cockpit.cpp Airlock.cpp CargoHold.cpp O2Room.cpp Engineering.cpp


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


