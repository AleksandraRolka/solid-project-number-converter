CXX=g++
CXXFLAGS=-Wall -g -pedantic

SOURCES=$(wildcard *.cpp)
OBJ=$(SOURCES:.cpp=.o)
HEADERS=$(wildcard *.h)

main: $(OBJ) $(HEADERS)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJ) 
%.o: %.cpp $(HEADERS)
	$(CXX) -c $< $(CXXFLAGS) 

# If the first argument is "run"...
ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

.SILENT: run

default: main

run:
	./main $(RUN_ARGS)
	

all: clean main

.PHONY: clean
clean:
	rm -f *.o main


