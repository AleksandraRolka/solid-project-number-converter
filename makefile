CXX=g++ 
CXXFLAGS=-Wall -g -pedantic
GTESTFLAGS=-lgtest -lpthread -lgtest -pthread

SOURCES=$(wildcard *.cpp)
OBJ=$(SOURCES: *.cpp=.o)
HEADERS=$(wildcard *.h)

UT_DIR = ut/
UT_SOURCES=$(wildcard $(UT_DIR)*.cpp)
UT_OBJ=$(UT_SOURCES:*.cpp=.o)
UT_HEADERS=$(wildcard $(UT_DIR)*.h)

main: $(OBJ) $(HEADERS)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJ)  $(GTESTFLAGS)
%.o: %.cpp $(HEADERS)
	$(CXX) -c $< $(CXXFLAGS) 
tests: $(UT_OBJ) $(HEADERS)
	$(CXX) -o $(UT_DIR)$@ $(CXXFLAGS) $(UT_OBJ) $(GTESTFLAGS)
%.o: %.cpp $(UT_HEADERS)
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

all: clean main tests

run:
	./main $(RUN_ARGS)

.PHONY: ut
ut:
	./$(UT_DIR)tests

.PHONY: clean
clean:
	rm -f *.o main $(UT_DIR)tests
