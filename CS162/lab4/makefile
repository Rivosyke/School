
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall #Turns on all warnings
CXXFLAGS += -pedantic-errors #Strictly enforce the standard
CXXFLAGS += -g #Debugging info
#CXXFLAGS += O3 #Optimation option

OBJS = Person.o utility.o Instructor.o Student.o University.o lab4.o Building.o
	
HEADERS = Person.hpp Instructor.hpp utility.hpp Student.hpp University.hpp Building.hpp

SRCS = Person.cpp Student.cpp utility.cpp Instructor.cpp University.cpp Building.cpp
 

#target: dependencies
#	rule to build	

default: clean lab4

lab4: ${HEADERS} ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab4

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm -f *.o
	rm -f lab4


