

# testing file

TERRORSRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,%.o, $(TERRORSRC))
testError=test
CC=g++
INCL= -I ../src/
CXXFLAG=-Wall -g
LD_FLAG=../src/libbtd.a


TEST=test

TEST:MainTest.o
	$(CC) $(INCL) -o $(TEST) MainTest.o $(LD_FLAG)
MainTest.o:MainTest.cpp
	$(CC) -c $(INCL) $(CXXFLAG) -o MainTest.o MainTest.cpp



#$(testError):$(OBJ)
#	$(CC)  $(INCL) -o testErr $(OBJ) $(LD_FLAG)
#%.o:%.cpp
#	$(CC) -c $(INCL) $(CXXFLAG) -o $@ $<

.PHONY:clean
clean:
	rm *.o

