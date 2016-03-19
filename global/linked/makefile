SHELL=/bin/bash
SRC=$(wildcard *.cc)
#SRC = tt.cc lib.cc
OBJ = $(patsubst %.cc, %.o, $(SRC))

EXE=./exe

exe: ${OBJ}
	g++ $^ -o $@

%.o: %.cc
	g++ -c $^ 

clean:
	rm *.[xo] ./exe
