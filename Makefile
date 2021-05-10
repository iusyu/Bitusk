# take a archive


ARCHIVENAME=libbtd.a
CXXFLAG=-c -std=c++11 -Wall

subsystem:
	cd src && make clean && make
	cd testing && make clean && make && ./testErr


.PHONY:clean
clean:
	rm *.o
