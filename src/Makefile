# take a archive


ARCHIVENAME=libbtd.a
CXXFLAG=-c -std=c++11 -Wall
INCLIDE=-I ../include/
SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o, $(SRCS))

$(ARCHIVENAME):$(OBJS)
	ar rcs $(ARCHIVENAME) *.o

%.o:%.cpp
	echo $(SRCS)
	g++ $(CXXFLAG) $(INCLIDE) -o $@ $<

.PHONY:clean
clean:
	rm *.o
