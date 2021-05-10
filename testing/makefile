

# testing file

TERRORSRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,%.o, $(TERRORSRC))
testError=test
CC=g++
INCL= -I ../include/
CXXFLAG=-Wall -g
LD_FLAG=../src/libbtd.a

$(testError):$(OBJ)
	$(CC)  $(INCL) -o testErr $(OBJ) $(LD_FLAG)
%.o:%.cpp
	$(CC) -c $(INCL) $(CXXFLAG) -o $@ $<

.PHONY:clean
clean:
	rm *.o

