CXX = g++
CXXFLAGS = -std=c++11 -Wall -fpic -O2
SRCS = mainTest.cpp Box.cpp Genetics.cpp SpawnPool.cpp
HEADERS = Box.h Genetics.h SpawnPool.h
OBJS = mainTest.o Box.o Genetics.o SpawnPool.h

all: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o knapsackGA

${OBJS}: ${SRCS}
	${CXX} -c $(@:.o=.cpp)

clear:
	rm -f *.o knapsackGA
