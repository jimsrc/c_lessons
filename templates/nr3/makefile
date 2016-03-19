#!/bin/bash

# evrthng that is not a file
.PHONY: default help object executable all clean 

#SOURCE_C = $(wildcard *.cc)
SOURCE_C = tt.cc nrr3_.cc #dummy.cc #nrr3_.cc
OBJECTS_C = $(patsubst %.cc, %.o, $(SOURCE_C))

tt.x: $(OBJECTS_C)
	g++ -o $@ $^

%.o: %.cc
	g++ -c $^ 

clean:
	rm *.[xo]
