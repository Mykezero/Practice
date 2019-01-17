CPPUTEST_HOME = /tools/cpputest-3.8

# Store C source and objects
src = $(wildcard src/*.c)
src_obj = $(src:.c=.o)

# Store CPP source and objects
test = $(wildcard tests/*.cpp)
test_obj = $(test:.cpp=.o)

obj = $(src_obj) $(test_obj)
bin = ./bin

# For compiling the C application code.
CC			= gcc
FLAGS_C 	= --coverage
LDFLAGS 	= --coverage -L$(CPPUTEST_HOME)/lib -lCppUTest

# For compiling cpputest with C++
CPP 		= g++
FLAGS_CPP  	= -I$(CPPUTEST_HOME)/include -D TEST -Isrc/

all: clean main test run cover
main:
	$(CC) $(FLAGS_C) src/*.c $(LDFLAGS) -o $(bin)/$@
test:
	$(CPP) $(FLAGS_CPP) src/*.c tests/*.cpp $(LDFLAGS) -o $(bin)/$@
clean:
	rm -f $(obj) $(bin)/test $(bin)/main
run: 
	$(bin)/test
cover:
	lcov --capture --directory . --output-file out/coverage.info
	genhtml out/coverage.info --output-directory out